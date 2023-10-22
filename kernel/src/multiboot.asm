section .multiboot

multiboot_header_start:
    dd 0xe85250d6										; magic number
    dd 0												; protected mode code
    dd multiboot_header_end - multiboot_header_start	; header length

    ; checksum: 0x100000000 - (magic + arch + header_size)
    dd 0x100000000 - (0xe85250d6 + 0 + (multiboot_header_end - multiboot_header_start))

multiboot_header_type:
    dw 0    ; type
multiboot_header_flags:
    dw 0    ; flags
multiboot_header_size:
    dd 8    ; size
multiboot_header_end: