#include "console.h"

uint8_t color = CON_DEFAULT_COLOR;
uint8_t cx = 0;
uint8_t cy = 0;

// Internal functions

void __advance_pos(int num) {
    cx++;

    if(cx > CONSOLE_W) {
        cx = 0;
        cy++;
    }
}

// Public functions

void con_setcolor(uint8_t new_color) {
    color = new_color;
}

void con_clear() {
    volatile uint16_t* video_memory = (uint16_t*)CON_VIDEO_MEMORY;

    for (int i = 0; i < CONSOLE_W * CONSOLE_H; i++) {
        *video_memory = (uint16_t)((color << 8) | ' ');
        video_memory++;
    }

    con_resetpos();
}

void con_writes(const char * str) {
    volatile uint16_t* video_memory = (uint16_t*)CON_VIDEO_MEMORY + (cy * CONSOLE_W + cx);
    int c = 0;

    while (*str) {
        *video_memory = (uint16_t)((color << 8) | *str);
        str++;
        video_memory++;
        c++;
    }

    __advance_pos(c);
}

void con_setpos(int x, int y) {
    cx = x;
    cy = y;
}

void con_writec(char c) {
    // TODO implement
}

void con_resetpos() {
    cx = 0;
    cy = 0;
}