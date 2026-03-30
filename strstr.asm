bits 64
section .text
global strstr

strstr:
    push r12
    push r13
    mov rax, 0
    mov r10, 0
    mov r13, 0
    cmp BYTE [rsi], 0
    je out

loop:
    mov r11, 0
    cmp BYTE [rdi + r10], 0
    je ret_null
    mov r12b, BYTE [rsi + r11]
    cmp BYTE [rdi + r10], r12b
    je start_check_substring
    add r10, 1
    jmp loop

out:
    mov rax, rdi
    add rax, r13
    pop r13
    pop r12
    ret

ret_null:
    mov rax, 0
    pop r13
    pop r12
    ret

start_check_substring:
    mov r13, r10
    jmp check_substring

check_substring:
    cmp BYTE [rsi + r11], 0
    je out
    cmp BYTE [rdi + r10], 0
    je loop
    mov r12b, BYTE [rsi + r11]
    cmp BYTE [rdi + r10], r12b
    jne loop
    add r10, 1
    add r11, 1
    jmp check_substring
