default rel

extern printf
extern scanf
global main

section .data
    fmt_in     db "%d", 0
    fmt_out    db "%s ", 0          ; Змінили формат на %s, бо ми будемо виводити рядок (string)
    newline    db 10, 0

section .bss
    array      resb 7
    temp_input resd 1
    bin_str    resb 9               ; Створюємо буфер на 9 байт: 8 байт для нулів та одиниць + 1 для кінця рядка (0)

section .text

main:            
    sub rsp, 40         


    ; === ЦИКЛ ВВОДУ (залишився без змін) ===
    mov rbx, 0                      
.input_loop:
    lea rcx, [fmt_in]               
    lea rdx, [temp_input]           
    call scanf

    mov eax, dword [temp_input]     
    lea rcx, [array]                
    mov byte [rcx + rbx], al        

    inc rbx                         
    cmp rbx, 7                      
    jl .input_loop                  

    ; === ЦИКЛ ВИВОДУ БІТІВ ===
    mov rbx, 0                      

.output_loop:
    ; 1. Беремо поточний байт з масиву
    lea r8, [array]
    mov al, byte [r8 + rbx]         ; al містить наше 8-бітне число
    
    ; 2. Готуємося до заповнення рядка
    lea r8, [bin_str]               ; r8 тепер вказує на початок нашого текстового буфера
    mov r9, 8                       ; r9 - лічильник бітів (8 ітерацій для 1 байта)

.bit_loop:
    mov dl, '0'                     ; За замовчуванням готуємо символ '0' (в ASCII це число 48)
    shl al, 1                       ; Зсуваємо al вліво на 1 біт. Найстарший біт потрапляє у Carry Flag (CF)
    
    jnc .write_bit                  ; Jump if Not Carry: якщо випав 0 (CF=0), стрибаємо далі
    mov dl, '1'                     ; Якщо ми сюди дійшли, значить CF=1. Змінюємо символ на '1' (ASCII 49)

.write_bit:
    mov byte [r8], dl               ; Записуємо '0' або '1' у наш буфер
    inc r8                          ; Зміщуємо вказівник буфера на наступний символ
    dec r9                          ; Зменшуємо лічильник бітів
    jnz .bit_loop                   ; Повторюємо, поки не витягнемо всі 8 бітів

    mov byte [r8], 0                ; Обов'язково додаємо нуль-термінатор в кінці рядка, щоб printf знав, де зупинитись

    ; 3. Виводимо готовий рядок
    lea rcx, [fmt_out]              ; 1-й аргумент: рядок формату "%s "
    lea rdx, [bin_str]              ; 2-й аргумент: наша створена стрічка з бітами
    call printf

    inc rbx                         ; Переходимо до наступного числа в масиві
    cmp rbx, 7                      
    jl .output_loop                 

    ; Фінальне перенесення рядка
    lea rcx, [newline]
    call printf

    add rsp, 32         
    pop rbx             
    xor eax, eax        
    ret