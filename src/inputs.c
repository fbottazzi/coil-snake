#include "inputs.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOUPPER(c) ('a'<=(c) && (c)<='z' ? (c)+'A'-'a' : (c) )



void getNameandLength (char* name,game_settings_t* game_settings)
{
    system("clear");
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
        getLength(game_settings);
    } else {
        getLength(game_settings);
        printf("Welcome %s! Starting game ...\n", name);
    }

    // Wait half a second while getting the stdin cursor in the correct position
    // and then erase the screen
    clock_t start = clock();
    while(c != '\n' && c != EOF) {
        c = getchar();
    }

    while(clock() - start < GETNAME_DELAY_MS*CLOCKS_PER_SEC/1000) ;
    system("clear");

    return;

}

#include <ncurses.h>


input_t getInput(int _timeout) {
    
    flushinp();
    napms(_timeout);
    int c = getch();
    input_t ans;
    switch( TOUPPER(c) ) {
        case 'W':
        case KEY_UP:
            ans = K_UP;
            break;        
        case KEY_LEFT:
        case 'A':
            ans = K_LEFT;
            break;
        case KEY_RIGHT:
        case 'D':
            ans = K_RIGHT;
            break;
        case KEY_DOWN:
        case 'S':
            ans = K_DOWN;
            break;
        case 'Q':
            ans = K_PAUSE;
            break;
        default:
            ans = K_NONE;
            break;
    }
    return ans;
}

void getLength(game_settings_t* thisgame)
{
    char num[MAX_LEN];
    char c;
    printf("please input initial length(max %d digits) \n",MAX_LEN);
    int i;
    for(i=0;(c=getchar())!='\n' && i<MAX_LEN;i++)
    {
        num[i]=c;

    }

    thisgame->init_length = atoi(num);
    if(thisgame->init_length>RECO_LEN)
    {
        printf("Snake way too long, not recommended\n");
    }
    
   
}

