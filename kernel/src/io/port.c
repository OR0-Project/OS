#include <io/port.h>


// Read a byte from an I/O port
uint8_t inportb(uint16_t port) {
    uint8_t data;
    __asm__ __volatile__("inb %1, %0" : "=a" (data) : "Nd" (port));
    return data;
}

// Write a byte to an I/O port
void outportb(uint16_t port, uint8_t data) {
    __asm__ __volatile__("outb %0, %1" : : "a" (data), "Nd" (port));
}