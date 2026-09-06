default rel

extern printf
extern scanf
global main

section .data
    fmt_in     db "%d", 0
    fmt_out    db "%d", 10, 0

section .bss
    array      resb 7
    temp_input resd 1

section .text

main:            
    push rbx
    sub rsp, 32

    mov rbx, 0
.input_loop:
    lea rcx, [fmt_in]
    lea rdx, [temp_input]
    call scanf

    mov eax, [temp_input]
    lea rcx, [array]
    mov [rcx + rbx], al

    inc rbx
    cmp rbx, 7
    jl .input_loop

    xor rax, rax
    mov rcx, 7
    lea rsi, [array]

.pack_loop:
    shl rax, 8
    movzx rdx, byte [rsi]
    or rax, rdx

    inc rsi
    dec rcx
    jnz .pack_loop

    mov rcx, 8
    xor rbx, rbx

.analyze_loop:
    mov rdx, rax
    and rdx, 01111111b

    test dl, dl
    jpo .skip_increment

    inc rbx

.skip_increment:
    shr rax, 7
    dec rcx
    jnz .analyze_loop

    lea rcx, [fmt_out]
    mov rdx, rbx
    call printf

    add rsp, 32
    pop rbx
    xor eax, eax
    ret
