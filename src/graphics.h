#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "food.h"
#include "body.h"

// Initializes and configs the graphics library (ncurses)
void initGraphics(void);

// Prints the walls & the snake
// On NULL pointers or negative width/height, returns INPUT_ERR, else returns 0
int printGameInit(const snake_t* snake, int width, int height);

// Erases the symbol of some position in the board
void eraseInBoard(int x, int y);

// Updates the head and the new tail, and prints the new food
// Doesn't erase the old food or tail
// On NULL pointers ignores the parameter and doesn't update/print it
void printInBoard(const part_t* head, const part_t* tail, const food_t* food);

// Erases the board and prints the game over message
void printGameOver(void);


#endif // GRAPHICS_H