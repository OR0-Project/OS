#ifndef __TIMER_H
#define __TIMER_H

#include "../../sys/types.h"

// Reads the timestamp counter using rdtsc
uint64_t read_tsc();

#endif