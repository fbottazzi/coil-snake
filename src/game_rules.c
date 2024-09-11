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

int runGame_v2(const game_settings_t* settings) {

    // Initialization of ncurses
    initGraphics(settings->_timeout);
    
    // Initialization of values
    snake_t snake;
    if( initSnake(&snake, settings->init_x, settings->init_y, settings->init_orient, settings->init_length) == HEAP_ERR) {
        endwin();
        return HEAP_ERR;
    }

    food_t food = newFood(snake.head, B_COL, B_ROW);
    state_t gamestate = PLAYING;
    int result = 0, score_accum = 0, lives = settings->lives;
    

    // Build board
    if( printGameInit(&snake, settings->width, settings->height) == INPUT_ERR) return INPUT_ERR;

    gamestate = play(&snake, &food, settings, &result);

    if(result < 0) {
        clear();
        printw("ERROOOOOOOOOOOR\n\n");
        // This should better after, probably a routine in the graphics lib
    } else {
        score_accum += result;
        printGameOver();
    }

    freeAll(snake.head);

    timeout(-1);
    getch();
    clear();
    endwin();

    return 0;
}

int runGame(const game_settings_t* settings) {
    /*
    initGraphics(settings->_timeout);
    
    snake_t snake;
    food_t food;
    input_t key = K_NONE;
    state_t gamestate = PLAYING;
    int error = 0, lives = settings->lives;

    if( initSnake(&snake, settings->init_x, settings->init_y, settings->init_orient, settings->init_length) == HEAP_ERR) {
        endwin();
        return HEAP_ERR;
    }
    
    food = newFood(snake.head, B_COL, B_ROW);
    if( printGameInit(&snake, settings->width, settings->height) == INPUT_ERR) return INPUT_ERR;

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
        
        if( checkFood(&food, &snake, settings->width, settings->height) == HEAP_ERR) {
            gamestate = GAMEOVER;
            error = HEAP_ERR;
        } else {
            printInBoard(snake.head, snake.tail, &food);
            // Print head, new food & re-print tail
            if( COLLISION(snake.head, settings->width, settings->height) ) gamestate = GAMEOVER;
        
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
    */
    return 0;
}

/* Dibujar la snake
   Crear una food (la inicial es recibida)
   Gametick -> update hasta que:
   * Presione pausa en un cierto gametick (el juego va a "quedar" en ese gametick) -> devuelve pause
   * Haya una collision -> devuelve GAMEOVER
*/

state_t play(snake_t* snake, food_t* food, const game_settings_t* settings, int* score) {

    input_t key = K_NONE;
    int ans;

    printSnake(snake);
    printInBoard(NULL, NULL, food);

    while(1) {
    
        // Wait one gametick (settings->_timeout miliseconds) and get input
        key = getKey();
        
        // Erase tail on the screen before deleting it on memory
        eraseInBoard(snake->tail->x, snake->tail->y);

        // First update
        switch(key) {
            case K_DOWN:
            case K_LEFT:
            case K_RIGHT:
            case K_UP:
                update(snake, (direction_t) key);
                break;
            case K_NONE:
                update(snake, snake->head->orient);
                break;
            case K_PAUSE:
                return PAUSE;
        }
        
        // Then check if food has to change and snake has to grow, or to die
        ans = checkFood(food, snake, settings->width, settings->height); // checkFood updates the snake and food if necesary        
        if(ans < 0) {
            *score = ans;
            return GAMEOVER;
        }

        // Check for collision
        ans = WALLCOLLISION(snake->head, settings->width, settings->height) ? 1 : 0;
        if( ans || isInsideSnake(snake->head->x, snake->head->y, snake->head->p2next) ) {
            
            printInBoard(NULL, snake->tail, food);
            refresh();
            napms(1000);
            eraseSnake(snake, 1);
            eraseInBoard(food->x, food->y);
            *score = snake->size;
            return GAMEOVER;
            
        }
        
        // Print head, new food &, if snake grew, re-print tail
        // No need on erasing old food because if it was eaten, it gets overwritten by the head
        printInBoard(snake->head, snake->tail, food);
        
        refresh();
    }

    return PAUSE;
}
