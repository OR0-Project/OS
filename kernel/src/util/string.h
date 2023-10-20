#ifndef _STRING_H
#define _STRING_H
#include "../sys/types.h"

uint8_t strlen(const char *str);
char * itoa(int value, char * str, int base);

#endif