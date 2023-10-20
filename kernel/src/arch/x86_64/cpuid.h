#ifndef __CPUID_H
#define __CPUID_H

#include "../../sys/types.h"

// Coreinfo structure
typedef struct coreinfo_t {
    uint32_t cores;
    uint32_t threads;
} coreinfo_t;

void cpuid(uint32_t code, uint32_t* a, uint32_t* b, uint32_t* c, uint32_t* d);
void get_cpu_brand_string(char* brand);
bool cpuid_can64();
bool cpuid_isi686();
coreinfo_t get_cpu_cores();

#endif