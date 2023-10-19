#include "./kern/kernel.h"
#include "./io/console.h"
#include "./util/string.h"
#include "./sys/types.h"

/**
 * Kernel entry point.
 * */
KERNEL_RESULT kmain() {
    con_setcolor(CON_DEFAULT_COLOR);
    con_clear();
    con_writes("OS Kernel V1.0.");

    // infinite loop
    while(1);

    return KERN_SUCCESS;
}
