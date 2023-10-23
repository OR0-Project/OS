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

// Gets the number of CPU cores
cpu_info_t get_cpu_cores() {
    uint32_t eax, ebx, ecx, edx;
	cpu_info_t ci;

    cpuid(1, &eax, &ebx, &ecx, &edx);
    ci.cores = (ecx >> 16) & 0xFF;
    ci.threads = eax & 0xFFFF;   

    return ci;
}