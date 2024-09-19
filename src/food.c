#include <stdlib.h>
#include "consts.h"
#include "food.h"


food_t newFood(const part_t* phead, int width, int height) {

    food_t food;
    do {
        food.x = rand() % width;
        food.y = rand() % height;
    } while( isInsideSnake(food.x, food.y, phead) );

    food.time = 0;
    return food;

}

int checkFood(food_t* p2food, snake_t* snake, int width, int height) {

    if(p2food == NULL || snake == NULL || width < 0 || height < 0)  return INPUT_ERR;

    // Check if food was eaten
    if(p2food->x == snake->head->x && p2food->y == snake->head->y) {
        *p2food = newFood(snake->head, width, height);
        return ( newNode(snake) == HEAP_ERR ? HEAP_ERR : 1 );
    } // Check if food came to its timeout
    else if(p2food->time >= TIME_MAX) {
        *p2food = newFood(snake->head, width, height);
    }
    (p2food->time) ++;
    return 0;

}