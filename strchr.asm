bits 64
section .text
global strchr
global index

index:
strchr:
    mov rax, 0
    push r10
    mov r10, 0

loop:
    cmp BYTE [rdi + r10], 0
    je ret_null
    cmp BYTE [rdi + r10], sil
    je out
    add r10, 1
    jmp loop

out:
    mov rax, rdi
    add rax, r10
    pop r10
    ret

ret_null:
    cmp rsi, 0
    je out
    mov rax, 0
    pop r10
    ret
