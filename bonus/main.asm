bits 64
section .data
    welcome db 'Welcome to the guessing game!', 0Ah, 0
    welcome_len equ $-welcome
    prompt db 'Guess a number between 1 and 10: ', 0
    prompt_len equ $-prompt
    correct db 'Correct!', 0Ah, 0
    correct_len equ $-correct
    incorrect db 'Incorrect. The correct number was 5.', 0Ah, 0
    incorrect_len equ $-incorrect
    buffer db 0

section .text
global _start

_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, welcome
    mov edx, welcome_len
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, prompt
    mov edx, prompt_len
    int 0x80

    mov eax, 3
    mov ebx, 0
    mov ecx, buffer
    mov edx, 3 ; read 3 bytes
    int 0x80

    cmp byte [buffer], '5'

    mov eax, 4
    mov ebx, 1
    je correct_guess
    mov ecx, incorrect
    mov edx, incorrect_len
    jmp end_game

correct_guess:
    mov ecx, correct
    mov edx, correct_len

end_game:
    int 0x80

    mov eax, 1
    xor ebx, ebx
    int 0x80
