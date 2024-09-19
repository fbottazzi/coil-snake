#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "food.h"
#include "body.h"
#include "progstates.h"

#define SCORE_WIDTH 5
#define MAX_SCORE 99999

// Initializes and configs the graphics library (ncurses)
void initGraphics(void);

// Prints the walls & the snake
// On NULL pointers or negative width/height, returns INPUT_ERR, else returns 0
int printGameInit(int width, int height);

void printSnake(const snake_t* snake, const food_t* food);

//prints score and lives during the game
void printHeader(int score, int lives);

// Updates the head and the new tail, erases the old tail, and prints the new food
// In case of conflict, priority of printing goes head > food > tail
// On NULL pointers ignores the parameter and doesn't update/print it
void printInBoard(const part_t* head, const part_t* tail, const food_t* food);

// Erases the symbol of some position in the board
void eraseInBoard(int x, int y);

void eraseSnake(const snake_t* snake, int reprintwall);

state_t printPause(const snake_t* snake, const food_t* food, const game_settings_t* settings);

// Erases the board and prints the game over message
void printGameOver(void);

void printErrorMessage(int error_code);


#endif // GRAPHICS_H