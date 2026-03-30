bits 64
section .text
global strpbrk

strpbrk:
    mov r10, 0

loop:
    mov r11, -1
    cmp BYTE [rdi + r10], 0
    je ret_null
    jmp check
end_loop:
    inc r10
    jmp loop

out:
    mov rax, rdi
    add rax, r10
    ret

ret_null:
    mov rax, 0
    ret

check:
    inc r11
    cmp BYTE [rsi + r11], 0
    je end_loop
    mov al, BYTE [rsi + r11]
    cmp BYTE [rdi + r10], al
    jne check
    je out
