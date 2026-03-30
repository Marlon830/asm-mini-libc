bits 64
section .text
global ffs

ffs:
    push rdi
    mov r10, 0
    cmp rdi, 0
    je out

loop:
    inc r10
    test rdi, 1
    jnz out
    shr rdi, 1
    jmp loop

out:
    mov rax, r10
    pop rdi
    ret
