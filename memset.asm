bits 64
section .text
global memset

memset:
    mov rax, rdi
    mov r10, 0

loop:
    cmp r10, rdx ; if i == 3
    je out
    mov BYTE [rdi + r10], sil ; str[i] = 'a'
    add r10, 1
    jmp loop

out:
    ret
