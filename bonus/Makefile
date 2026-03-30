##
## EPITECH PROJECT, 2023
## B-ASM-400-MPL-4-1-asmminilibc-marlon.pegahi
## File description:
## Makefile
##

OBJ = main.o

all:
	nasm -f elf64 main.asm

	$(LD) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) a.out

re:	fclean all
