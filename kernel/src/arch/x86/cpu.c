#include <arch/cpu.h>



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
bool cpuid_can64() {
    uint32_t registers[4];

    cpuid(0x80000001, &registers[0], &registers[1], &registers[2], &registers[3]);

    // Check if the LM (Long Mode) bit is set
    return (registers[3] >> 29) & 0b1u;
}

// Checks whether the system is i686 (Pentium Pro/P6) capable.
bool cpuid_isi686() {
    uint32_t eax, ebx, ecx, edx;
    cpuid(1, &eax, &ebx, &ecx, &edx);
    return (edx >> 15) & 0b1u;
}

// Gets the number of CPU cores
cpu_info_t get_cpu_cores() {
    uint32_t eax, ebx, ecx, edx;
	cpu_info_t ci;

    cpuid(1, &eax, &ebx, &ecx, &edx);
    ci.cores = (ecx >> 16) & 0xFF;
    ci.threads = eax & 0xFFFF;   

    return ci;
}