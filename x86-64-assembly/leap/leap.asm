section .text
global leap_year

leap_year:
    push rbp
    mov rbp, rsp

    ; Get an int as 1st argument (rdi, 4bytes)
    ; first, are we divisible by 100
    mov rdx, rdi
    mov rsi, 100
    idiv rsi
    ; checking remainder
    cmp rdx, 0
    jne byf

    mov rdx, rdi
    mov rsi, 400
    idiv rsi
    cmp rdx, 0
    jne not_leap
    jmp leap

    ; Hit only if not divisible by 100
    byf:
    mov rdx, rdi
    mov rsi, 4
    idiv rsi
    cmp rdx, 0
    jne not_leap
    jmp leap

    not_leap:
    mov rax, 0
    jmp endf

    leap:
    mov rax, 1

    endf:
    pop rbp
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
