bits 64
section .text
global memmove

; first = rdi
; second = rsi
; third = rdx

memmove:
    push r12
    mov rax, rdi
    mov r10, 0
    mov r11, 0

    mov r12, rdx

    cmp rdi, rsi
    jge move_loop

cpy_loop:
    cmp rdx, 0
    jle out

    cmp r10, rdx ; if i == 3
    je out

    push rax
    mov al, BYTE [rsi + r10]
    mov BYTE [rdi + r10], al ; dest[i] = src[i]
    pop rax

    inc r10

    jmp cpy_loop

out:
    pop r12
    ret

move_loop:
    cmp r12, 0 ; if i == 0
    je out

    mov r11b, BYTE [rsi + r12 - 1]
    mov BYTE [rdi + r12 - 1], r11b ; dest[i] = src[i]

    sub r12, 1

    jmp move_loop
