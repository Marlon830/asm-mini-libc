bits 64
section .text
global strcspn

strcspn:
    mov r10, 0

loop:
    mov r11, -1
    cmp BYTE [rdi + r10], 0
    je out
    jmp check
end_loop:
    inc r10
    jmp loop

out:
    mov rax, r10
    ret

check:
    inc r11
    cmp BYTE [rsi + r11], 0
    je end_loop
    mov al, BYTE [rsi + r11]
    cmp BYTE [rdi + r10], al
    jne check
    je out
