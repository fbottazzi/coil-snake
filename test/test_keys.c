#include <stdio.h>
#include <curses.h>
#include "../src/game_rules.h"

#define T (300) // Number of miliseconds of the timeout


#define KEY_NAME(c) (aux_names[(c)+2])
const char* aux_names[] = {
    "UP", "LEFT", "", "RIGHT", "DOWN", "PAUSE", "NONE"
};

int main(void)
{

    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    key_t c = NONE;
    while(c != PAUSE) {

        
        clear();
        printw("Detecting key... ");
        c = getInputInTimeout(T);
        printw("%s\n", KEY_NAME(c));
        printw("Detecting key... ");
        c = getInputInTimeout(T);
        printw("%s\n", KEY_NAME(c));
        printw("Detecting key... ");
        c = getInputInTimeout(T);
        printw("%s\n", KEY_NAME(c));
    }

    printw("Ending program\n");
    endwin();

    return 0;
}



