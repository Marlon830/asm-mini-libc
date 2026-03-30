bits 64
section .text
global strcmp

; first = rdi | dil
; second = rsi | sil

strcmp:
    mov rax, 0
    push r10
    mov r10, 0

loop:
    push r11
    mov r11b, BYTE [rsi + r10]
    cmp BYTE [rdi + r10], r11b
    je equal_char ; if src[i] == dest[i]
    jl less_char ; if src[i] < dest[i]
    jg greater_char ; if src[i] > dest[i]
end_loop:
    pop r11

    cmp BYTE [rdi + r10], 0 ; if src[i] == '\0'
    je out
    cmp BYTE [rsi + r10], 0 ; if dest[i] == '\0'
    je out


    add r10, 1
    jmp loop

out:
    push r11
    mov r11, 0
    mov r11b, BYTE [rdi + r10]
    sub r11b, BYTE [rsi + r10]
    mov al, r11b
    pop r11
    pop r10
    ret

equal_char:
    mov rax, 0
    jmp end_loop

less_char:
    mov rax, -1
    pop r11
    jmp out

greater_char:
    mov rax, 1
    pop r11
    jmp out
