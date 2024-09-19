#ifndef FOOD_H
#define FOOD_H

#include "body.h"

typedef struct {
    int x;
    int y;
    int time;
} food_t;

#define TIME_MAX 20

// Generates new random food position outside of the snake
food_t newFood(const part_t* phead, int width, int height);

// Checks if food must be regenerated
// If it's been eaten, lets the snake grow
// Returns 1 if food's been eaten, 0 if not or HEAP_ERR on malloc error
int checkFood(food_t* p2food, snake_t* snake, int width, int height);


#endif // FOOD_H