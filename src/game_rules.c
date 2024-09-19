#include <ncurses.h>
#include <stdlib.h>
#include "consts.h"
#include "graphics.h"
#include "inputs.h"

#include "game_rules.h"

#define RANDINT(a, b) ( (a) + rand() % ( 1 + (b)-(a) ) )



void runGame(game_settings_t* settings, gameinfo_t* game_info) {

    // Initialization of ncurses, some counters and game board
    initGraphics();
    int result = 0, lives = settings->lives;
    game_info->score = 0;

    result = printGameInit(settings->width, settings->height);
    if(result < 0) {
        printErrorMessage(-result);
        return;
    }


    while(lives > 0) {

        // Initialization of values
        getRandPos(settings);
        snake_t snake;
        result = initSnake(&snake, settings->init_x, settings->init_y, settings->init_orient, settings->init_length);
        if(result < 0) break;

        // Play until death
        result = play(&snake, settings, &(game_info->score), lives);
        if(result < 0 || result == GAMEOVER) break;
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
    state_t gamestate = PLAYING;

    printSnake(snake, &food);
    
    while(gamestate == PLAYING) {
    
        // Wait one gametick and get input
        input = getInput(settings->speed);
        
        // Erase tail on the screen before deleting it on memory
        eraseInBoard(snake->tail->x, snake->tail->y);
        eraseInBoard(food.x, food.y);

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
                gamestate = printPause(snake, &food, settings);
                continue;
        }
        
        // Then check if food has to change and snake has to grow, or to die
        ans = checkFood(&food, snake, settings->width, settings->height); // checkFood updates the snake and food if necesary        
        if(ans < 0) {
            return ans;
        } else if(ans == 1) {
            *score += snake->size * snake->time_since_growth;
            if(*score >= MAX_SCORE) *score = MAX_SCORE;
            snake->time_since_growth = 0;
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
            return EXIT;
            
        }

        // Print head, new food &, if snake grew, re-print tail
        // No need on erasing old food because if it was eaten, it gets overwritten by the head
        printInBoard(snake->head, snake->tail, &food);
        printHeader(*score, lives);
        
        refresh();
    }

    return GAMEOVER;
}

void getRandPos(game_settings_t* settings)
{
    static const direction_t dirs[] = {N, E, W, S};
    
    settings->init_orient = dirs[ RANDINT(0, 3) ];

    switch(settings->init_orient) {
        case N:
            settings->init_x = RANDINT(0, settings->width - 1); // every possible row
            settings->init_y = RANDINT(1, settings->height - settings->init_length); // Tail must be at most in y = width-1
            break;
        case S:
            settings->init_x = RANDINT(0, settings->width - 1); // every possible row
            settings->init_y = RANDINT(settings->init_length - 1, settings->height - 2); // Tail must be at least in y = 0
            break;
        case E:
            settings->init_x = RANDINT(settings->init_length - 1, settings->width - 2); // every possible row
            settings->init_y = RANDINT(0, settings->height - 1); // Tail must be at least in y = 0
            break;
        case W:
            settings->init_x = RANDINT(1, settings->width - settings->init_length); // every possible row
            settings->init_y = RANDINT(0, settings->height - 1); // Tail must be at most in y = width-1
            break;
    }

}