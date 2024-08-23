#include <ncurses.h>
#include "../src/body.h"
#include "../src/game_rules.h"
#include "../src/graphics.h"
#include "../src/food.h"
#include "../src/consts.h"

#define TRY(function, err_code) if((function) == (err_code))    return (err_code)



typedef enum {
    PLAYING,
    PAUSE,
    GAMEOVER,
    MENU_MAIN,
    MENU_TOPSCORES,
    MENU_SETTINGS
} state_t;

int main(void)
{
    INITCURSES();

    snake_t snake;
    food_t food;
    key_t key;
    state_t gamestate = PLAYING;
    // unsigned int lives = 3, score = 0;
    // register int i;

    TRY( initSnake(&snake, BC_X, BC_Y, N, 3), HEAP_ERR );
    food = newFood(snake.head, B_COL, B_ROW);
    printGameInit(&snake, B_COL, B_ROW);

    while(gamestate == PLAYING) {
        
        clear();
        key = getInputInTimeout(2000);

        switch(key) {
            case K_PAUSE:
                gamestate = PAUSE;
                break;
            case K_NONE:
                update(&snake, snake.head->orient);
                break;
            default:
                update(&snake, (direction_t) key);
                break;
        }
        
        if( COLLISION(snake.head, B_COL, B_ROW) ) {
            gamestate = GAMEOVER;
        } else {
            
            TRY( checkFood(&food, &snake, B_COL, B_ROW), HEAP_ERR );
            // This already updates the length of the snake,
            // so for now no need for score counter

        }

        printBoard(&snake, &food, B_COL, B_ROW);

    }
    clear();
    if(gamestate == PAUSE) {
        printw("Game paused\n");
    } else if(gamestate == GAMEOVER) {
        printw("Game over\n");
    }
    printw("Quitting\n");

    freeAll(snake.head);
    while(1) ;
    endwin();

    return 0;
}
