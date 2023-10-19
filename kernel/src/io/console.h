#ifndef __CONSOLE_H
#define __CONSOLE_H
#include "../sys/types.h"

#define CON_VIDEO_MEMORY 0xB8000
#define CON_DEFAULT_COLOR 0x0F
#define CONSOLE_W 80
#define CONSOLE_H 25

void con_setcolor(uint8_t new_color);
void con_clear();
void con_writes(const char * str);
void con_writec(char c);
void con_resetpos();
void con_setpos(int x, int y);

#endif