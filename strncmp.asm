bits 64
section .text
global strncmp

; first = rdi | dil
; second = rsi | sil

strncmp:
    mov rax, 0
    mov r10, 0
    dec rdx
    cmp rdx, -1
    je out

loop:
    mov r11b, BYTE [rsi + r10]
    cmp BYTE [rdi + r10], r11b
    je equal_char ; if src[i] == dest[i]
    jl out ; if src[i] < dest[i]
    jg out ; if src[i] > dest[i]
end_loop:

    cmp BYTE [rdi + r10], 0 ; if src[i] == '\0'
    je out
    cmp BYTE [rsi + r10], 0 ; if dest[i] == '\0'
    je out
    cmp r10, rdx
    je out


    add r10, 1
    jmp loop

out:
    mov r11, 0
    mov r11b, BYTE [rdi + r10]
    sub r11b, BYTE [rsi + r10]
    mov al, r11b
    movsx eax, al
    ret

equal_char:
    mov rax, 0
    jmp end_loop
