#include "cpuid.h"

void cpuid(uint32_t code, uint32_t* a, uint32_t* b, uint32_t* c, uint32_t* d) {
    asm volatile (
        "cpuid"
        : "=a" (*a), "=b" (*b), "=c" (*c), "=d" (*d)
        : "a" (code)
    );
}

// Get brand string
void get_cpu_brand_string(char* brand) {
    uint32_t registers[4];
    uint32_t code;

    // Retrieve CPU brand string (concatenating sub-leaves)
    for (code = 0x80000002; code <= 0x80000004; code++) {
        cpuid(code, &registers[0], &registers[1], &registers[2], &registers[3]);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                *brand++ = (char)(registers[i] >> (j * 8));
            }
        }
    }

    // Null-terminate the brand string
    *brand = '\0';
}

// Checks whether the system can work in long mode.
int cpuid_can64() {
    uint32_t registers[4];

    cpuid(0x80000001, &registers[0], &registers[1], &registers[2], &registers[3]);

    // Check if the LM (Long Mode) bit is set
    return (registers[3] & (1 << 29)) != 0;
}

// Gets the number of CPU cores
coreinfo_t get_cpu_cores() {
    uint32_t eax, ebx, ecx, edx;
    coreinfo_t ci;

    cpuid(1, &eax, &ebx, &ecx, &edx);
    ci.cores = (ecx >> 16) & 0xFF;
    ci.threads = eax & 0xFFFF;   

    return ci;
}