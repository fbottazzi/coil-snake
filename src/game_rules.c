#include <time.h>
#include <ncurses.h>
#include "body.h"
#include "consts.h"

#include "game_rules.h"


key_t getInputInTimeout(unsigned int time_in_ms) {
    
    /* GOTTA TRY THIS:
        Making the getch non-blocking (w/o timeout)
        and then try to "get rid" of all inputs except for the last one
        or sth I don't know
        Me looking at ncurses documentation:  >:(
    */

    clock_t start = clock();
    if(time_in_ms > 20) {
        timeout(time_in_ms-20);
    }
    
    int c = getch();
    while(clock()-start < time_in_ms*CLOCKS_PER_SEC/1000) {
        continue;
    }

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
        
        case KEY_EXIT:
        case 'q':
            return PAUSE;

        default:
            return NONE;

    }

}