#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include "consts.h"
#include "graphics.h"
#include "gameInfo.h"
#include "game_rules.h"

#define TOUPPER(c) ('a'<=(c) && (c)<='z' ? (c)+'A'-'a' : (c) )

input_t getKey(void) {
    
    int c = getch();
    switch( TOUPPER(c) ) {
        case 'W':
        case KEY_UP:
            return K_UP;
        
        case KEY_LEFT:
        case 'A':
            return K_LEFT;
        
        case KEY_RIGHT:
        case 'D':
            return K_RIGHT;
        
        case KEY_DOWN:
        case 'S':
            return K_DOWN;
        
        case 'Q':
            return K_PAUSE;
        
        default:
            return K_NONE;
    }
}

int runGame(int width, int height, int gametick_ms, int init_x, int init_y, direction_t init_orient, unsigned int init_length) {
    
    gameInfo thisGame;
    getName(&thisGame);

    initGraphics(gametick_ms);
    srand(time(NULL));

    snake_t snake;
    food_t food;
    input_t key = K_NONE;
    state_t gamestate = PLAYING;
    int error = 0;

    if( initSnake(&snake, init_x, init_y, init_orient, init_length) == HEAP_ERR) {
        endwin();
        return HEAP_ERR;
    }

    food = newFood(snake.head, init_x, init_y);
    printGameInit(&snake, width, height);

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
        
        if( checkFood(&food, &snake, init_x, init_y) == HEAP_ERR) {
            gamestate = GAMEOVER;
            error = HEAP_ERR;
        } else {
            printInBoard(snake.head, snake.tail, &food);
            // Print head, new food & re-print tail
            if( COLLISION(snake.head, init_x, init_y) ) gamestate = GAMEOVER;
        
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
    endwin();

    storeGame(&thisGame, &snake);
    
    return error ? error : snake.size;

}

