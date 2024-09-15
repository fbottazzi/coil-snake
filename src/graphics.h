#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "food.h"
#include "body.h"

// Initializes and configs the graphics library (ncurses)
void initGraphics(int _timeout);

// Prints the walls & the snake
// On NULL pointers or negative width/height, returns INPUT_ERR, else returns 0
int printGameInit(int width, int height);

void printSnake(const snake_t* snake);

// Updates the head and the new tail, erases the old tail, and prints the new food
// In case of conflict, priority of printing goes head > food > tail
// On NULL pointers ignores the parameter and doesn't update/print it
void printInBoard(const part_t* head, const part_t* tail, const food_t* food);

// Erases the symbol of some position in the board
void eraseInBoard(int x, int y);

void eraseSnake(const snake_t* snake, int reprintwall);

// Erases the board and prints the game over message
void printGameOver(void);

//prints score and lives during the game
void printHeader(int score, int lives);


#endif // GRAPHICS_H