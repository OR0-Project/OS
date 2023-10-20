#include "timer.h"

// Reads the timestamp counter using rdtsc
uint64_t read_tsc() {
    uint32_t low, high;
    asm volatile("rdtsc" : "=a" (low), "=d" (high));
    return ((uint64_t)high << 32) | low;
}