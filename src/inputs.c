#include "inputs.h"

void getName (char* name)
{
    printf("Please input your name (maximum %d characters)", NAME_MAX);

    char c;
    int i;
    for(i=0; (c=getchar())!='\n' && i<NAME_MAX;i++)
    {
        name[i] = c;
    }
    while(c != '\n' && c != EOF) {
        c = getchar();
    }
    return;
}


input_t getKey(void) {
    
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