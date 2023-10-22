#ifndef __CPUID_H
#define __CPUID_H

#include <types.h>


// Coreinfo structure
typedef struct cpu_info_t {
    uint32_t cores;
    uint32_t threads;
	uint8_t msr : 1;
} cpu_info_t;


void cpuid(uint32_t code, uint32_t* a, uint32_t* b, uint32_t* c, uint32_t* d);  // TODO: cpuid in asm
void get_cpu_brand_string(char* brand);
bool cpuid_can64();
bool cpuid_isi686();
cpu_info_t get_cpu_cores();

#endif