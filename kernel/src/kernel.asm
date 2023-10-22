global _start

section .text
extern main

_start:
    mov esp, stack
    call main

    ; idle loop
    hlt
    jmp $

section .bss
stack resb 4096  ; 4KB stack space