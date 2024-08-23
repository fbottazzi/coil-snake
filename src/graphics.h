#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <ncurses.h>
#include "food.h"
#include "body.h"

#define INITCURSES() do { \
    initscr(); \
    noecho(); \
    cbreak(); \
    keypad(stdscr, TRUE); \
    nodelay(stdscr, TRUE); \
} while(0)


// Prints the board
// On NULL pointers or negative width/height, returns INPUT_ERR, else returns 0
// The "printing preference" is head > food, body/tail > head
int printBoard(const snake_t* snake, const food_t* food, int width, int height);

void printGameOver(void);
void eraseBoard(void);
int printGameInit(const snake_t* snake, int width, int height);

#endif // GRAPHICS_H