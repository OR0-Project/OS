#ifndef PORT_H
#define PORT_H

#include "../sys/types.h"

// Read a byte from an I/O port
uint8_t inportb(uint16_t port);

// Write a byte to an I/O port
void outportb(uint16_t port, uint8_t data);

#endif