#include <arch/msr.h>
#include <arch/cpu.h>


// Checks if the CPU supports model specific registers
bool msr_available() {
    static uint32_t eax, ebx, ecx, edx;
    cpuid(1, &eax, &ebx, &ecx, &edx);
    return edx & (1 << 5);
}

// Writes a model specific register
void msr_write(uint32_t msr_id, uint64_t msr_value) {
    asm volatile ( "wrmsr" : : "c" (msr_id), "A" (msr_value) );
}

// Reads a model specific register.
uint64_t msr_read(uint32_t msr_id) {
    uint64_t msr_value;
    asm volatile ( "rdmsr" : "=A" (msr_value) : "c" (msr_id) );
    return msr_value;
}