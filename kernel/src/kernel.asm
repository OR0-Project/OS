; Entry point for the kernel

global _start

section .text
_start:
    mov esp, stack
    call kmain

    ; idle loop
    hlt
    jmp $

section .bss
stack resb 4096  ; 4KB stack space

section .data
; Define any data structures or variables here

section .text
extern kmain