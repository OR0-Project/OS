#include "kutil.h"
#include "../io/console.h"
#include "../util/string.h"

// Gets the program counter
uint32_t get_program_counter() {
    uint32_t pc;

    asm volatile (
        "call 1f\n"   // Call the next instruction and push the return address onto the stack
        "1: pop %0"   // Pop the return address into pc
        : "=r" (pc)
    );
    
    return pc;
}

// Throws a kernel exception
void throw_ex(const char * ident, const char* message) {
    // Dump registers
    uint32_t registers[4];
    uint32_t pcounter = get_program_counter();

    // Read the values of eax, ebx, ecx, and edx
    asm volatile (
        "mov %%eax, %0\n"
        "mov %%ebx, %1\n"
        "mov %%ecx, %2\n"
        "mov %%edx, %3\n"
        : "=r" (registers[0]), "=r" (registers[1]), "=r" (registers[2]), "=r" (registers[3])
    );

    // Write a pretty message
    con_writec('\n');
    con_setcolor(0xC, 0);
    con_writes("! kernel exception occured !\n");

    // Dump location and program counter
    con_writes(" @ -> ");
    con_writes(ident);
    con_writes(" :: 0x");
    char pc_val[9];
    itoa(pcounter, pc_val, 16);
    con_writes(pc_val);
    con_writec('\n');

    // Dump message
    con_writes(" $ -> ");

    if(message == NULL)
        con_writes("<none>");
    else
        con_writes(message);

    con_writec('\n');

    // Dump regs
    con_writes(" r -> \n");

    for(int i = 0; i < 4; i++) {
        char reg[] = "eax";
        reg[1] = reg[1] + i;
        con_writes("   - ");
        con_writes(reg);
        con_writes(" = 0x");

        // Get hex val
        char valstr[] = "00000000";
        itoa(reg[i], valstr, 16);
        con_writes(valstr);

        con_writec('\n');
    }

    // Hang
    while(1);
}