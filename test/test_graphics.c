#include <ncurses.h>
#include "../src/body.h"
#include "../src/food.h"
#include "../src/graphics.h"
#include "../src/consts.h"
#include <time.h>

#define TIMEOUT 30

int main() {

    initscr(); //Initialize the window
    noecho(); //Don't echo keypresses
    keypad(stdscr, TRUE);
    cbreak();
    timeout(TIMEOUT);
    curs_set(FALSE);

    snake_t test_snake;
    food_t food;

    //eraseBoard();

    if( initSnake(&test_snake, B_COL/2, B_ROW/2, N, 3) == HEAP_ERR) {
        printw("HEAP ERR\n\n");
        endwin();
        return 0;
    }
    

    printGameInit(&test_snake, B_COL, B_ROW);
    printw("\nInput f for new food, N, S, E, W to update, q to exit:\n");


    char c;
    int cont = 1;
    while( cont ) {

        c = getch();
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
            case 'q':
            case 'Q':
                cont = 0;
        }
        

        eraseBoard();
        printBoard(&test_snake, &food, B_COL, B_ROW);
    }

    printGameOver();

    endwin();
    return 0;

}