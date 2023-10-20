#include "console.h"

volatile uint16_t* video_memory = (uint16_t*)CON_VIDEO_MEMORY;
uint16_t color = CON_DEFAULT_COLOR;
uint8_t cx = 0;
uint8_t cy = 0;

// Advances the cursor position
void _advance_pos(int count) {
    cx++;

    if(cx > CONSOLE_W) {
        cx = 0;
        cy ++;

        if(cy > CONSOLE_H) {
            // TODO scroll
        }
    }
}

// Sets the console color
void con_setcolor(uint8_t fore, uint8_t back) {
    color = (back << 4) | (fore & 0x0F);
}

// Clears the console
void con_clear() {
    con_setpos(0, 0);
}

// Writes a string to the console
void con_writes(const char * str) {
    while(*str) {
        con_writec(*str);
        str++;
    }
}

// Writes a character to the console.
void con_writec(char c) {
    // Handle newline
    if(c == '\n') {
        cx = 0;
        cy ++;
        return;
    }

    video_memory[cy * CONSOLE_W + cx] = (uint16_t)((color << 8) | c);
    _advance_pos(1);
}

// Sets the console position
void con_setpos(int x, int y) {
    cx = x;
    cy = y;
}