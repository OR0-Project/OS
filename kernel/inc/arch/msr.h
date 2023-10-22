#ifndef __MSR_H
#define __MSR_H

#include <types.h>


// Checks if the CPU supports model specific registers
bool msr_available();

// Writes a model specific register
void msr_write(uint32_t msr_id, uint64_t msr_value);

// Reads a model specific register.
uint64_t msr_read(uint32_t msr_id);

#endif