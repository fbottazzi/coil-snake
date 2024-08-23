#include <time.h>
#include <ncurses.h>
#include "consts.h"
#include "game_rules.h"


key_t getInputInTimeout(unsigned int time_in_ms) {
    
    clock_t start = clock();
    while( clock() - start < CLOCKS_PER_SEC*time_in_ms/1000 ) ;

    return K_NONE;

    /*
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
            return K_UP;

        case 'S':
        case 's':
        case KEY_DOWN:
            return K_DOWN;
        
        case 'A':
        case 'a':
        case KEY_LEFT:
            return K_LEFT;
        
        case 'D':
        case 'd':
        case KEY_RIGHT:
            return K_RIGHT;
        
        case KEY_BACKSPACE:
        case 'p':
            return K_PAUSE;

        default:
            return K_NONE;

    }
    */
}