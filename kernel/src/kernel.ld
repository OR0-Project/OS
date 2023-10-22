ENTRY(_kernel_main)

SECTIONS {
	/* load kernel at 1MiB */
    . = 1M;

	.boot BLOCK(4K) : ALIGN(4K) {
        *(.multiboot)
	}

    .text BLOCK(4K) : ALIGN(4K) {
        *(.text)
    }

  	.rodata BLOCK(4K) : ALIGN(4K) {
  		*(.rodata)
  	}

    .data BLOCK(4K) : ALIGN(4K) {
    	*(.data)
    }

    .bss BLOCK(4K) : ALIGN(4K) {
		*(.bss)
		*(COMMON)
    }

    /DISCARD/ : {
    	*(.eh_frame)
        *(.comment)
    }
}