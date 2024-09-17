#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include "consts.h"
#include "graphics.h"
#include "inputs.h"

#include "game_rules.h"

#define DELAY_TIME 1000

int runGame(const game_settings_t* settings) {

    // Initialize game info
    gameinfo_t this_game;
    getName(this_game.name);
    this_game.score = 0;

    // Initialization of ncurses, some counters and game board
    initGraphics(settings->_timeout);
    int result = 0, lives = settings->lives;
    state_t gamestate = PLAYING;
    if( printGameInit(settings->width, settings->height) == INPUT_ERR) return INPUT_ERR;


    while(lives > 0) {

        snake_t snake;
        // Initialization of values
        result = initSnake(&snake, settings->init_x, settings->init_y, settings->init_orient, settings->init_length);
        if(result < 0) break;

        food_t food = newFood(snake.head, B_COL, B_ROW);

        // Play until death
        gamestate = play(&snake, &food, settings, &result, lives, &this_game);
        if(result < 0) break;
        
        lives --;
        this_game.score = (result > this_game.score) ? result : this_game.score;
        
        freeAll(snake.head);
        
    }

    if(result < 0) {
        
        clear();
        printw("ERROR. Press any key to go back to main menu\n\n");
        refresh();
        napms(500);
        timeout(-1);
        getch();
    
    } else {
        storeGame(&this_game);
        printGameOver();
    }

    clear();
    endwin();

    return 0;
}

/* Dibujar la snake
   Crear una food (la inicial es recibida)
   Gametick -> update hasta que:
   * Presione pausa en un cierto gametick (el juego va a "quedar" en ese gametick) -> devuelve pause
   * Haya una collision -> devuelve GAMEOVER
*/
state_t play(snake_t* snake, food_t* food, const game_settings_t* settings, int* score, int lives,gameInfo_t* this_game){

    input_t input = K_NONE;
    int ans;

    printSnake(snake);
    printInBoard(NULL, NULL, food);
    refresh();
    napms(DELAY_TIME);
    flushinp();

    while(1) {
    
        // Wait one gametick (settings->_timeout miliseconds) and get input
        input = getInput();
        
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
            napms(DELAY_TIME);
            eraseSnake(snake, 1);
            eraseInBoard(food->x, food->y);
            *score = snake->size;
            return GAMEOVER;
            
        }
        
        // Print head, new food &, if snake grew, re-print tail
        // No need on erasing old food because if it was eaten, it gets overwritten by the head
        printInBoard(snake->head, snake->tail, food);

        

        printHeader(this_game->score+*score, lives);
        
        refresh();
    }

    return PAUSE;
}
