#include <stdio.h>
#include <curses.h>
#include "../src/game_rules.h"

#define KEY_NAME(c) (aux_names[(c)+2])
const char* aux_names[] = {
    "UP", "LEFT", "", "RIGHT", "DOWN", "PAUSE", "NONE"
};

int main(void)
{
    
    INITKEYCHECK();

    key_t c = NONE;
    while(c != PAUSE) {
        printw("Detecting key... ");
        c = getInputInTimeout(700);
        printw("%d\n", c);
    }

    printw("Ending program\n");
    endwin();

    return 0;
}



