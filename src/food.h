#ifndef FOOD_H
#define FOOD_H

#include "body.h"

/* ==================== */
/* Typedefs & Constants */

typedef struct {
    int x;
    int y;
    int time; // Time "alive" in gameticks
} food_t;

#define TIME_MAX 20 // Maximum number of gameticks of the function


/* =================== */
/* Functions & Macros  */

// Generates new random food position outside of the snake
food_t newFood(const part_t* phead, int width, int height);

// Checks if food must be regenerated
// If it's been eaten, let's the snake grow and generates new food and returns 1
// If not, updates the time, generates new food if it has reached the max time, and returns 0
// On malloc error, returns HEAP_ERR
int checkFood(food_t* p2food, snake_t* snake, int width, int height);


#endif // FOOD_H