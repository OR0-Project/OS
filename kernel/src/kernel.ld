ENTRY(kmain)

/* OUTPUT_FORMAT("binary")
OUTPUT_ARCH(i386) */

SECTIONS {
    . = 1M;

    .boot : {
        *(.multiboot)
    }

    .text : {
        *(.text)
    }

    .rodata : {
        *(.rodata)
    }

    .data : {
        *(.data)
    }

    .bss : {
        *(.bss)
    }

    /DISCARD/ : {
        *(.eh_frame)
        *(.comment)
    }
}