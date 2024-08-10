#include <stdlib.h>
#include "consts.h"
#include "body.h"
#include "food.h"

food_t newFood(const part_t* phead, int board_width, int board_height) {

    food_t food;
    do {
        food = {rand() % board_width, rand() % board_height};
    } while( isInsideSnake(food.x, food.y, phead) );

    return food;

}

int checkFood(food_t* p2food, snake_t* snake, unsigned int width, unsigned int height) {

    if(p2food->x == snake->head->x && p2food->y == snake->head->y) {
        *p2food = newFood(snake->head, width, height);
        return ( newNode(snake) == HEAP_ERR ? HEAP_ERR : 1 );
    }
    return 0;

}