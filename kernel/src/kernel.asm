global _kernel_main
extern kernel_main

; text section
section .text
bits 32

; main kernel entry
; -----------------
_kernel_main:
    mov esp, stack_top

    ; jesse we must enter long mode
    call setup_paging
    call enable_paging

    lgdt [gdt64.pointer]
    jmp gdt64.code_segment:_kernel_main64
    hlt


; func to setup page tables
; -------------------------
setup_paging:
    mov eax, pt_l3
    or eax, 0b11 ; present, writable
    mov [pt_l4], eax

    mov eax, pt_l2
    or eax, 0b11 ; present writable
    mov [pt_l3], eax

    mov ecx, 0
.loop:
    mov eax, 0x200000 ; 2Mib
    mul ecx
    or eax, 0b10000011 ; present, writable, huge page
    mov [pt_l2 + ecx * 8], eax
    
    inc ecx ; counter
    cmp ecx, 512 ; checks if whole table is mapped
    jne .loop

    ret

; function to enable paging
; --------------------------
enable_paging:
    ; give the cpu our precious page table
    mov eax, pt_l4
    mov cr3, eax

    ; enable PAE
    mov eax, cr4
    or eax, 1 << 5
    mov cr4, eax

    ; enable long mode
    mov ecx, 0xC0000080
    rdmsr
    or eax, 1 << 8
    wrmsr

    ; enable paging
    mov eax, cr0
    or eax, 1 << 31
    mov cr0, eax
    
    ret

bits 64
; 64 bit entry function
; ---------------------
_kernel_main64:
    xor ax, ax
    mov ss, ax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; its time to C
    call kernel_main
    hlt


section .bss
align 4096

; page tables
pt_l4:
    resb 4096
pt_l3:
    resb 4096
pt_l2:
    resb 4096

; stack def
stack_bottom:
    resb 4096 * 4 ; 16 KiB
stack_top:



section .rodata
gdt64:
    dq 0 ; zero entry
.code_segment: equ $ - gdt64
    dq (1 << 43) | (1 << 44) | (1 << 47) | (1 << 53) ; code segment
.pointer:
    dw $ - gdt64 - 1
    dq gdt64

