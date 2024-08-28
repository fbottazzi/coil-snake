#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include "../src/game_rules.h"
#include "../src/body.h"
#include "../src/graphics.h"
#include "../src/food.h"
#include "../src/consts.h"

#define TRY(function, err_code) if((function) == (err_code))    return (err_code)
#define TIMEOUT 300

// Menus module

typedef enum {
    PLAYING,
    PAUSE,
    GAMEOVER,
    MENU_MAIN,
    MENU_TOPSCORES,
    MENU_SETTINGS
} state_t;




int main(void) {
    
    initGraphics(TIMEOUT);
    srand(time(NULL));

    snake_t snake;
    food_t food;
    input_t key = K_NONE;
    state_t gamestate = PLAYING;
    int error = 0;

    if( initSnake(&snake, BC_X, BC_Y, N, 3) == HEAP_ERR) {
        endwin();
        return HEAP_ERR;
    }

    food = newFood(snake.head, B_COL, B_ROW);
    printGameInit(&snake, B_COL, B_ROW);

    while(gamestate == PLAYING) {
        
        key = getKey();

        eraseInBoard(snake.tail->x, snake.tail->y);
        switch(key) {
            case K_DOWN:
            case K_LEFT:
            case K_RIGHT:
            case K_UP:
                update(&snake, (direction_t) key);
                break;
            case K_NONE:
                update(&snake, snake.head->orient);
                break;
            case K_PAUSE:
                gamestate = PAUSE;
                break;
            default:
                gamestate = GAMEOVER;
                error = INPUT_ERR;
                break;
        }
        
        if( checkFood(&food, &snake, B_COL, B_ROW) == HEAP_ERR) {
            gamestate = GAMEOVER;
            error = HEAP_ERR;
        } else {
            printInBoard(snake.head, snake.tail, &food);
            // Print head, new food & re-print tail
            if( COLLISION(snake.head, B_COL, B_ROW) ) gamestate = GAMEOVER;
        
        }
        
        refresh();
    }

    if(error) {
        clear();
        printw("ERROOOOOOOOOOOR\n\n");
        // This should better after, probably a routine in the graphics lib
    } else {
        printGameOver();
    }

    freeAll(snake.head);

    timeout(-1);
    getch();
    clear();
    endwin();

}
