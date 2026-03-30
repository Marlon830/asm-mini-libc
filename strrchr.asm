bits 64
section .text
global strrchr
global rindex
extern strlen

rindex:
strrchr:
    call strlen wrt ..plt
    mov r10, rax ; i = strlen(s)
    mov rax, 0

loop:
    cmp r10, -1
    je ret_null
    cmp BYTE [rdi + r10], sil
    je out
    dec r10
    jmp loop

out:
    mov rax, rdi
    add rax, r10
    ret

ret_null:
    mov rax, 0
    ret
