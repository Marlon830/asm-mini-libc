##
## EPITECH PROJECT, 2023
## B-ASM-400-MPL-4-1-asmminilibc-marlon.pegahi
## File description:
## Makefile
##

OBJ = strlen.o \
		strchr.o \
		strrchr.o \
		memset.o \
		memcpy.o \
		strcmp.o \
		memmove.o \
		strncmp.o \
		strcasecmp.o \
		strstr.o \
		strpbrk.o \
		strcspn.o \
		ffs.o \
		strfry.o \
		memfrob.o

TARGET = libasm.so

all:
	nasm -f elf64 strlen.asm
	nasm -f elf64 strchr.asm
	nasm -f elf64 strrchr.asm
	nasm -f elf64 memset.asm
	nasm -f elf64 memcpy.asm
	nasm -f elf64 strcmp.asm
	nasm -f elf64 memmove.asm
	nasm -f elf64 strncmp.asm
	nasm -f elf64 strcasecmp.asm
	nasm -f elf64 strstr.asm
	nasm -f elf64 strpbrk.asm
	nasm -f elf64 strcspn.asm
	nasm -f elf64 ffs.asm
	nasm -f elf64 strfry.asm
	nasm -f elf64 memfrob.asm

	$(LD) -shared -o $(TARGET) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(TARGET)
	$(RM) unit_tests
	$(RM) *.gcno
	$(RM) *.gcda

re:	fclean all

gdb_test: re
	$(RM) $(TARGET)
	ar rcs libasm.a $(OBJ)
	gcc -o gdb_exe main.c -fno-builtin -W -Wall -Wextra -L./ -lasm

debug_test: re
	gcc main.c -fno-builtin -W -Wall -Wextra
	LD_PRELOAD=./libasm.so:$$LD_PRELOAD ./a.out

tests_run: re
	gcc -o unit_tests tests/*.c -fno-builtin -W -Wall -Wextra --coverage -lcriterion
	LD_PRELOAD=./libasm.so:$$LD_PRELOAD ./unit_tests

fonctionnal_tests_run: re
	python tests/fonctionnal_tests.py
