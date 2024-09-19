#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include "consts.h"
#include "graphics.h"
#include "inputs.h"

#include "game_rules.h"

void runGame(const game_settings_t* settings, gameinfo_t* game_info) {

    

    // Initialization of ncurses, some counters and game board
    initGraphics(settings->_timeout);
    int result = 0, lives = settings->lives;
    game_info->score = 0;

    result = printGameInit(settings->width, settings->height);
    if(result < 0) {
        printErrorMessage(-result);
        return;
    }


    while(lives > 0) {

        // Initialization of values
        
        snake_t snake;
        result = initSnake(&snake, settings->init_x, settings->init_y, settings->init_orient, settings->init_length);
        if(result < 0) break;

        // Play until death
        result = play(&snake, settings, &(game_info->score), lives);
        if(result < 0) break;
        printHeader(game_info->score, --lives);
        
        
        freeAll(snake.head);
        
    }

    if(result < 0) {
        printErrorMessage(-result);
    } else {
        printGameOver();
    }

    clear();
    endwin();

    return;
}

/* Gametick -> update hasta que:
   * Presione pausa en un cierto gametick (el juego va a "quedar" en ese gametick) -> devuelve pause
   * Haya una collision -> devuelve GAMEOVER
*/
int play(snake_t* snake, const game_settings_t* settings, int* score, int lives) {

    if(snake == NULL || settings == NULL || score == NULL) {
        return INPUT_ERR;
    }

    food_t food = newFood(snake->head, settings->width, settings->height);
    input_t input = K_NONE;
    int ans;
    

    printSnake(snake, &food);
    
    while(1) {
    
        // Wait one gametick (settings->_timeout miliseconds) and get input
        input = getInput(settings->_timeout);
        
        // Erase tail on the screen before deleting it on memory
        eraseInBoard(snake->tail->x, snake->tail->y);

        // First update
        switch(input) {
            case K_DOWN:
            case K_LEFT:
            case K_RIGHT:
            case K_UP:
                update(snake, (direction_t) input);
                break;
            case K_NONE:
                update(snake, snake->head->orient);
                break;
            case K_PAUSE:
                return PAUSE;
        }
        
        // Then check if food has to change and snake has to grow, or to die
        ans = checkFood(&food, snake, settings->width, settings->height); // checkFood updates the snake and food if necesary        
        if(ans < 0) {
            return ans;
        }

        // Check for collision
        ans = WALLCOLLISION(snake->head, settings->width, settings->height) ? 1 : 0;
        if( ans || isInsideSnake(snake->head->x, snake->head->y, snake->head->p2next) ) {
            
            // MAKE THIS A FUNCTION
                            printInBoard(NULL, snake->tail, &food);
                            napms(1000);
                            eraseSnake(snake, ans);
                            eraseInBoard(food.x, food.y);
            //
            *score += snake->size;
            return GAMEOVER;
            
        }

        // Print head, new food &, if snake grew, re-print tail
        // No need on erasing old food because if it was eaten, it gets overwritten by the head
        printInBoard(snake->head, snake->tail, &food);
        printHeader(*score + snake->size, lives);
        
        refresh();
    }

    return PAUSE;
}


void getRandPos(game_settings_t* settings)
{
    srand(time(NULL));
    settings->init_x = rand()%B_ROW;
    settings->init_y = rand()%B_COL;
}