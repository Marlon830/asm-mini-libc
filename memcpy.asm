bits 64
section .text
global memcpy

; first = rdi
; second = rsi
; third = rdx

memcpy:
    mov rax, rdi
    mov r10, 0

loop:
    cmp rdx, 0
    jle out

    cmp r10, rdx ; if i == 3
    je out

    push rax
    mov al, BYTE [rsi + r10]
    mov BYTE [rdi + r10], al ; dest[i] = src[i]
    pop rax

    inc r10

    jmp loop

out:
    ret
