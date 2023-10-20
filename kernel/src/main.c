#include "./kern/kernel.h"
#include "./io/console.h"
#include "./util/string.h"
#include "./sys/types.h"

// For testing
#include "./arch/x86_64/cpuid.h"

#define OS_BANNER "                 .___\n\
  ____  ______ __| _/\n\
 /  _ \\/  ___// __ | \n\
(  <_> )___ \\/ /_/ | \n\
 \\____/____  >____ | \n\
           \\/     \\/\n\n"

// Shows the kernel startup banner
void show_startup_banner() {
    // Show kernel brand and system info
    con_setcolor(0xA, 0);
    con_writes(":: OS Kernel v1.0. Copyright (C) 2023.\n\n");
    con_setcolor(0xF, 0);

    con_writes(OS_BANNER);

    char brand[49];
    get_cpu_brand_string(brand);

    con_setcolor(0xE, 0);
    con_writes("Processor: ");
    con_setcolor(0xF, 0);
    con_writes(brand);
    con_writec('\n');
    con_setcolor(0xE, 0);
    con_writes("64-Bit Capable: ");
    con_setcolor(0xF, 0);
    
    if(cpuid_can64())
        con_writes("Yes");
    else
        con_writes("No");
}

/**
 * Kernel entry point.
 * */
KERNEL_RESULT kmain() {
    con_setcolor(0xF, 0);
    con_clear();

    show_startup_banner();

    // infinite loop
    while(1) {}

    return KERN_SUCCESS;
}
