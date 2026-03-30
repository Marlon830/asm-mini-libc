bits 64
section .text
global memfrob

memfrob:
    mov rax, rdi
    mov r10, 0

loop:
    cmp r10, rsi
    je out
    xor BYTE [rax + r10], 42
    inc r10
    jmp loop

out:
    ret
