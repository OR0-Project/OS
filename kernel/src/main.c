#include "./kern/kernel.h"
#include "./io/console.h"
#include "./util/string.h"
#include "./sys/types.h"

// For testing
#include "./arch/x86_64/cpuid.h"

/**
 * Kernel entry point.
 * */
KERNEL_RESULT kmain() {
    con_setcolor(0xF, 0);
    con_clear();

    // Show kernel brand and system info
    con_setcolor(0xA, 0);
    con_writes(":: OS Kernel v1.0. Copyright (C) 2023.\n\n");
    con_setcolor(0xF, 0);

    char brand[49];
    get_cpu_brand_string(brand);

    con_setcolor(0xE, 0);
    con_writes("Processor: ");
    con_setcolor(0xF, 0);
    con_writes(brand);
    con_writec('\n');

    // infinite loop
    while(1) {}

    return KERN_SUCCESS;
}
