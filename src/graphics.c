#include <curses.h>
#include <stdlib.h>
#include "body.h"
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
        addch(symbols[WALL]);
    }
    addch('\n');

    for(i = 0; i < width; i++) {
        addch(symbols[WALL]); // Left wall

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
            } else if(isInsideSnake(j, i, snake->head->p2next)) {//DOES NOT WORKl
                c = symbols[BODY];
            }
            
            addch(c);

        }

        addch(symbols[WALL]); // Right wall
        addch('\n');

    }

    // Print bottom wall
    for(i = 0; i < width+2; i++) {
        addch(symbols[WALL]);
    }
    addch('\n');
    
    return 0;

}


void eraseBoard(void)
{
    clear();
    return;
}

void printGameOver(void)
{
    printw(
    " _______  _______  __   __  _______    _______  __   __  _______  ______   \n"
    "|       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |  \n"
    "|    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||  \n"
    "|   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_ \n"
    "|   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  |\n"
    "|   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | |\n"
    "|_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_|\n"
    );

    return;
    // Fuente https://patorjk.com/software/taag/#p=testall&f=Graffiti&t=GAME%20OVER
}

void printGameInit(const snake_t* snake, int width, int height)
{
    if(snake == NULL || width < 0 || height < 0)    return INPUT_ERR;
    int i, j;
    
    // Print top wall
    for(i = 0; i < width+2; i++) {
        addch(symbols[WALL]);
    }
    addch('\n');

    for(i = 0; i < width; i++) {
        addch(symbols[WALL]); // Left wall

        for(j = 0; j < height; j++) {
            char c = symbols[NONE];
            
            if(COORDS_EQUAL(snake->head, j, i)) {
                c = symbols[HEAD];
            }

            // If head == tail or head is inside body, tail or body is drawn (for collision graphics)
            if(COORDS_EQUAL(snake->tail, j, i)) {
                c = symbols[TAIL];
            } else if(isInsideSnake(j, i, snake->head->p2next)) {//DOES NOT WORKl
                c = symbols[BODY];
            }
            
            addch(c);

        }

        addch(symbols[WALL]); // Right wall
        addch('\n');

    }

    // Print bottom wall
    for(i = 0; i < width+2; i++) {
        addch(symbols[WALL]);
    }
    addch('\n');
    
    return 0;
}


