bits 64
section .text
global strlen

strlen:
    mov rax, 0

loop:
    cmp BYTE [rdi + rax], 0
    je out
    add rax, 1
    jmp loop

out:
    ret
