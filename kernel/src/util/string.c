#include "string.h"

// Gets the string length
uint8_t strlen(const char *str) {
    uint8_t i;

    for(i = 0; str[i] != '\0'; i++);

    return i;
}