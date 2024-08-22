#include <time.h>
#include <ncurses.h>
#include "body.h"
#include "consts.h"

#include "game_rules.h"


key_t getInputInTimeout(unsigned int time_in_ms) {
    
    clock_t start = clock();
    
    int c, aux = getch();
    
    while(aux != ERR && clock()-start < time_in_ms*CLOCKS_PER_SEC/1000) {
        c = aux;
        aux = getch();
    }

    while(clock()-start < time_in_ms*CLOCKS_PER_SEC/1000) continue;

    switch(c) {
        case 'W':
        case 'w':
        case KEY_UP:
            return UP;

        case 'S':
        case 's':
        case KEY_DOWN:
            return DOWN;
        
        case 'A':
        case 'a':
        case KEY_LEFT:
            return LEFT;
        
        case 'D':
        case 'd':
        case KEY_RIGHT:
            return RIGHT;
        
        case KEY_BACKSPACE:
        case 'p':
            return PAUSE;

        default:
            return NONE;

    }

}