#include <ncurses.h>
#include "consts.h"

#include "game_rules.h"

#define TOUPPER(c) ('a'<=(c) && (c)<='z' ? (c)+'A'-'a' : (c) )

key_t getKey(void) {
    
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
