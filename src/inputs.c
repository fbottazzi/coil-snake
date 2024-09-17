#include "inputs.h"

#include <stdio.h>
#include <time.h>


void getName (char* name)
{
    
    printf("Please input your name (maximum %d characters):\n", NAME_MAX);

    char c;
    int i;
    // Get characters from stdin
    for(i = 0; (c=getchar()) != '\n' && i < NAME_MAX; i++)
    {
        name[i] = c;
    }
    name[i+1] = '\0';

    // Check correct input and print initialization message
    if(c != '\n') {
        printf("Too large username, starting the game with the name %s ...\n", name);
    } else {
        printf("Welcome %s! Starting game ...\n", name);
    }

    // Wait half a second while getting the stdin cursor in the correct position
    // and then erase the screen
    clock_t start = clock();
    while(c != '\n' && c != EOF) {
        c = getchar();
    }

    while(clock() - start < CLOCKS_PER_SEC/2) ;
    fflush(stdout);

    return;

}

#include <ncurses.h>

input_t getInput(void) {
    
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