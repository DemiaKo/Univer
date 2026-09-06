default rel

section .data
    fmt_in      db "%d", 0
    fmt_out     db "%d ", 0
    fmt_newline db 10, 0
    
    msg_fail    db "Умова не виконалась! Елемент %d на позиції [%d][%d] не дає остачу 3.", 10, 0
    msg_ok      db "Умова виконалась! Елемент %d підходить.", 10, 0
    msg_none    db "Елементів з остачею 3 при діленні на 4 не знайдено.", 10, 0

section .bss
    n resd 1
    array_pointer resq 1
    
    max_val resd 1
    max_i   resq 1
    max_j   resq 1
    found   resb 1

section .text
    global main
    extern scanf
    extern printf
    extern malloc
    extern free
    extern SetConsoleOutputCP

main:
    sub rsp, 40   

    mov rcx, 65001
    call SetConsoleOutputCP     

    lea rcx, [fmt_in]
    lea rdx, [n]
    call scanf

    movsxd rax, dword [n]
    mov rbx, 8
    mul rbx                 
    mov rcx, rax
    call malloc
    mov [array_pointer], rax

    xor rbx, rbx            
.alloc_rows:
    movsxd rcx, dword [n]
    cmp rbx, rcx
    jge .input_matrix       

    mov rax, 4
    movsxd rcx, dword [n]
    mul rcx                 
    mov rcx, rax
    call malloc

    mov rcx, [array_pointer]
    mov [rcx + rbx*8], rax  

    inc rbx                 
    jmp .alloc_rows

.input_matrix:
    xor r12, r12            
.in_row:
    movsxd rax, dword [n]
    cmp r12, rax
    jge .print_matrix       

    xor r13, r13            
.in_col:
    movsxd rax, dword [n]
    cmp r13, rax
    jge .in_row_next        

    mov rcx, [array_pointer]
    mov rdx, [rcx + r12*8]  
    lea rdx, [rdx + r13*4]  
    
    lea rcx, [fmt_in]
    call scanf              

    inc r13                 
    jmp .in_col

.in_row_next:
    inc r12                 
    jmp .in_row

.print_matrix:
    xor r12, r12            
.out_row:
    movsxd rax, dword [n]
    cmp r12, rax
    jge .find_max

    xor r13, r13            
.out_col:
    movsxd rax, dword [n]
    cmp r13, rax
    jge .out_row_next       

    mov rcx, [array_pointer]
    mov rdx, [rcx + r12*8]       
    mov edx, dword [rdx + r13*4] 

    lea rcx, [fmt_out]
    call printf

    inc r13                 
    jmp .out_col

.out_row_next:
    lea rcx, [fmt_newline]
    call printf
    inc r12                 
    jmp .out_row

.find_max:
    mov byte [found], 0

    xor r12, r12
.search_row:
    movsxd rax, dword [n]
    cmp r12, rax
    jge .check_condition

    xor r13, r13
.search_col:
    movsxd rax, dword [n]
    cmp r13, rax
    jge .search_row_next

    mov rcx, [array_pointer]
    mov rdx, [rcx + r12*8]
    mov eax, dword [rdx + r13*4]

    mov ecx, eax 
    cdq                     
    mov r8d, 4
    idiv r8d           
    cmp edx, 3
    jne .search_col_next  

    cmp byte [found], 0
    je .update_max       

    cmp ecx, dword [max_val]
    jle .search_col_next  

.update_max:
    mov byte [found], 1      
    mov dword [max_val], ecx    
    mov qword [max_i], r12    
    mov qword [max_j], r13   

.search_col_next:
    inc r13
    jmp .search_col

.search_row_next:
    inc r12
    jmp .search_row

.check_condition:
    cmp byte [found], 0
    je .not_found    

 
    mov rax, 1
    add rax, [max_i]
    add rax, [max_j]
    mov r8d, eax      

    mov eax, dword [max_val]
    cdq                
    idiv r8d             
    cmp edx, 3
    je .success          

    lea rcx, [msg_fail]
    movsxd rdx, dword [max_val]
    mov r8, [max_i]
    mov r9, [max_j]
    call printf
    jmp .end

.success:
    lea rcx, [msg_ok]
    movsxd rdx, dword [max_val]
    call printf
    jmp .end

.not_found:
    lea rcx, [msg_none]
    call printf

  
.end:
    add rsp, 40
    ret