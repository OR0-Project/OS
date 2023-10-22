global _kernel_main


section .bss
align 16
stack_bottom:
resb 4096
stack_top:

section .text
extern kernel_main

_kernel_main:
    mov esp, stack_top
    call kernel_main
    hlt