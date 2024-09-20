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

// Prints the snake with a little delay after printing,
// to give some reaction time to the user at the beginning
void printSnake(const snake_t* snake, const food_t* food);

// Prints score and lives
void printHeader(int score, int lives);

// Updates the head and the new tail, erases the old tail, and prints the new food
// In case of conflict, priority of printing goes head > food > tail
// On NULL pointers ignores the parameter and doesn't update/print it
void printInBoard(const part_t* head, const part_t* tail, const food_t* food);

// Erases the symbol of some position in the board
void eraseInBoard(int x, int y);

// Erases all the snake body
// If reprintwall != 0, replaces the snake's head with a wall symbol
void eraseSnake(const snake_t* snake, int reprintwall);

// Returns GAMEOVER if the user chooses to quit the game and EXIT if the user chooses to resume
state_t printPause(const snake_t* snake, const food_t* food, const game_settings_t* settings);

// Erases the board and prints the game over message
void printGameOver(void);

void printErrorMessage(int error_code);


#endif // GRAPHICS_H