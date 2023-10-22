global _kernel_main

section .text
extern kernel_main

_kernel_main:
    mov esp, stack
    mov ebp, stack
    call kernel_main
    hlt

section .bss
stack resb 4096  ; 4KB stack space