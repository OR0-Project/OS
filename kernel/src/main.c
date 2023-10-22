#include "./kern/kernel.h"
#include "./kern/kutil.h"
#include "./kern/kmem.h"
#include "./io/console.h"
#include "./util/string.h"
#include "./sys/types.h"
#include "./build.h"

// For testing
#include "./arch/x86/cpuid.h"
#include "./arch/x86/timer.h"

#define OS_BANNER "                 .___\n\
  ____  ______ __| _/\n\
 /  _ \\/  ___// __ | \n\
(  <_> )___ \\/ /_/ | \n\
 \\____/____  >____ | \n\
           \\/     \\/\n\n"

// Shows the kernel startup banner
void show_startup_banner() {
    // Show kernel brand and system info
    con_setpos(0, 0);
    con_setcolor(0xA, 0);
    con_writes(":: OS Kernel v1.0. Copyright (C) 2023.\n");
    con_writes(":: Commit: ");
    con_writes(B_GIT_HASH);
    con_writes(", Compiled: ");
    con_writes(B_COMPTIME_START);
    con_writes("\n\n");
    con_setcolor(0xF, 0);

    con_writes(OS_BANNER);

    // Check if an i686 processor was found
    // This is the minimum for this kernel
    if(!cpuid_isi686()) {
        throw_ex("kmain", "i686 processor or higher required!");
    }

    // Get CPU info
    char brand[49];
    get_cpu_brand_string(brand);
    con_setcolor(0xE, 0);
    con_writes("Processor: ");
    con_setcolor(0xF, 0);

    // Check if CPU name is known
    if(strisws(brand))
        con_writes("Generic x86 Processor");
    else
        con_writes(brand);

    con_writec('\n');
    con_setcolor(0xE, 0);
    con_writes("64-Bit Capable: ");
    con_setcolor(0xF, 0);
    
    if(cpuid_can64())
        con_writes("Yes\n\n");
    else
        con_writes("No\n\n");
}

// Sets up non paged kernel memory space
void setup_kmem_space() {
    con_writes("Setting up non-paged kernel memory space (");
    
    // Get kern mem space size
    int size = (KMEM_NP_MAX - KMEM_NP_BASE) / 1024 / 1024;
    char buf[4];
    itoa(size, buf, 10);
    con_writes(buf);
    con_writes(" megabytes)...\n");

    // Init
    kmem_init();

    // Do self test to ensure allocator is working correctly
    void * ptr = kmalloc(32);

    if(ptr)
        con_writes("Kmem self test succeeded!\n");
    else
        throw_ex("kmain", "Failed to setup kernel memory space.");

    kfree(ptr);
}

/**
 * Kernel entry point.
 * */
KERNEL_RESULT kmain() {
    con_setcolor(0xF, 0);
    con_clear();

    // Show startup banner
    show_startup_banner();

    // Setup kernel memory space
    setup_kmem_space();

    // Create exception dialog
    throw_ex("kmain", "End of kernel - development needed");

    // infinite loop
    while(1) {}

    return KERN_SUCCESS;
}
