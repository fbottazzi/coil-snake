/* ============

    MUST FIX SOMETHING WITH THE TAIL DIRECTION,
    SNAKE PARTS' DIRECTION MUST BE FROM WHERE THE COME, NOT WHERE THEY GO
    THAT IMPLIES CHANGING NEWNODE & UPDATE

   ============ */



#include <ncurses.h>
#include "../src/game_rules.h"
#include "../src/body.h"
#include "../src/graphics.h"
#include "../src/food.h"
#include "../src/consts.h"

#define TRY(function, err_code) if((function) == (err_code))    return (err_code)
#define TIMEOUT 50

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
    timeout(-1);


    snake_t snake;
    food_t food;
    key_t key = K_NONE;
    state_t gamestate = PLAYING;
    int error = 0;

    if( initSnake(&snake, BC_X, BC_Y, N, 3) == HEAP_ERR) {
        endwin();
        return HEAP_ERR;
    }

    printGameInit(&snake, B_COL, B_ROW);

    while(gamestate == PLAYING) {
        
        key = getKey();
        // =====================================================
        const char* keys[] = {"K_UP", "K_LEFT", "", "K_RIGHT", "K_DOWN", "K_PAUSE", "K_NONE"};
        mvprintw(8+B_COL+3, 1, "Input: %s\n", keys[key+2]);

        // =====================================================

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

    getch();
    endwin();


    /*
    
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
    */

}