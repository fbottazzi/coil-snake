#include <ncurses.h>
#include "../src/body.h"
#include "../src/food.h"
#include "../src/graphics.h"
#include "../src/game_rules.h"
#include "../src/consts.h"
#include <time.h>

#define TIMEOUT 30

int main() {

    initGraphics();

    snake_t snake;
    food_t food;
    key_t input;

    if( initSnake(&snake, B_COL/2, B_ROW/2, N, 3) == HEAP_ERR) {
        printw("HEAP ERR\n\n");
        endwin();
        return 0;
    }
    
    printGameInit(&snake, B_COL, B_ROW);
    mvprintw("\nInput f for new food, WASD or keys to update, q to exit:\n");

    food = newFood(snake.head, B_COL, B_ROW);
    printInBoard(NULL, NULL, &food);

    do {

        input = getKey();
        switch(input) {
            case K_DOWN:
            case K_LEFT:
            case K_RIGHT:
            case K_UP:
                eraseInBoard(snake.tail->x, snake.tail->y);
                update(&snake, (direction_t) input);
                printInBoard(snake.head, snake.tail, &food);
        }

    } while(input != K_PAUSE);

    
    
    endwin();
    return 0;

}