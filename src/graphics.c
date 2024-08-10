#include <stdio.h>
#include "body.h"
#include "food.h"
#include "consts.h"

#include "graphics.h"

enum {
    HEAD,
    BODY,
    TAIL,
    FOOD,
    WALL,
    NONE
};

const char symbols[] = "SO-X. ";

#define COORDS_EQUAL(ptr, x_pos, y_pos) ((ptr)->x == (x_pos) && (ptr)->y == (y_pos))

int printBoard(const snake_t* snake, const food_t* food, int width, int height) {

    if(snake == NULL || food == NULL || width < 0 || height < 0)    return INPUT_ERR;
    int i, j;
    
    // Print top wall
    for(i = 0; i < width+2; i++) {
        putchar(symbols[WALL]);
    }
    putchar('\n');
    
    for(i = 0; i < width; i++) {
        putchar(symbols[WALL]); // Left wall

        for(j = 0; j < height; j++) {
            char c = symbols[NONE];
            
            // If head is above food, head is drawn (for growth graphics)
            if(COORDS_EQUAL(food, j, i)) {
                c = symbols[FOOD];
            }
            if(COORDS_EQUAL(snake->head, j, i)) {
                c = symbols[HEAD];
            }

            // If head == tail or head is inside body, tail or body is drawn (for collision graphics)
            if(COORDS_EQUAL(snake->tail, j, i)) {
                c = symbols[TAIL];
            } else if(isInsideSnake(j, i, snake->head->p2next)) {
                c = symbols[BODY];
            }
            
            putchar(c);

        }

        putchar(symbols[WALL]); // Right wall
        putchar('\n');

    }

    // Print bottom wall
    for(i = 0; i < width+2; i++) {
        putchar(symbols[WALL]);
    }
    putchar('\n');
    
    return 0;

}