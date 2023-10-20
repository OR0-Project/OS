#ifndef __KUTIL_H
#define __KUTIL_H
#include "../sys/types.h"

// Gets the program counter
uint32_t get_program_counter();

// Throws a kernel exception
inline void throw_ex(const char * ident, const char* message);

#endif