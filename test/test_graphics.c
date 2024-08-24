#include <ncurses.h>
#include "../src/body.h"
#include "../src/food.h"
#include "../src/graphics.h"
#include "../src/consts.h"
#include <stdio.h>
#include <time.h>

int main() {

    initscr();
    cbreak();

    snake_t test_snake;
    food_t food;

    //eraseBoard();

    if( initSnake(&test_snake, B_COL/2, B_ROW/2, N, 3) == HEAP_ERR) {
        printf("HEAP ERR\n\n");
        return 0;
    }
    

    printGameInit(&test_snake, B_COL, B_ROW);
    printf("\nInput f for new food, N, S, E, W to update, q to exit:\n");


    char c;
    while( (c=getchar()) != 'q' ) {

        switch(c) {
            case 'f':
                food = newFood(test_snake.head, B_COL, B_ROW);
                break;
            case 'N':
                update(&test_snake, N);
                break;
            case 'W':
                update(&test_snake, W);
                break;
            case 'E':
                update(&test_snake, E);
                break;
            case 'S':
                update(&test_snake, S);
                break;
        }
        
        while(c != '\n') c = getchar();

        eraseBoard();
        printBoard(&test_snake, &food, B_COL, B_ROW);
    }

    endwin();
    return 0;

}