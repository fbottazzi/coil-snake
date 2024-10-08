#include "inputs.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

/* ========= */
/* Constants */

#define TICK_MS 10
#define MAX_DIG 4
#define MAX_SPEED ( sizeof(ticks_per_gametick) / sizeof(ticks_per_gametick[0]) )

const int ticks_per_gametick[] = {100, 50, 30, 40};


/* ===================== */
/* Macros & protoypes */

#define TOUPPER(c) ('a'<=(c) && (c)<='z' ? (c)+'A'-'a' : (c) )
#define MIN(a,b) ( (a) < (b) ? (a) : (b) )

// Gets input from std and turns it into an int
// Returns the int, 0 if 'q' was pressed or INPUT_ERR on incorrect input format
// The stdin buffer doesn't get any extra thrash
int getInt(int max_dig);

// Displays a generic menu that lets the user customize
// the value of an int variable *value, between min and ma
// name is the description of the variable
void getValue(int* value, int min, int max, const char name[]);


/* ========= */
/* Functions */

void getName(char* name)
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
    } else {
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

input_t getInput(int speed) {
    
    flushinp();
    input_t ans = K_NONE;

    for (int i = 0; i < ticks_per_gametick[speed-1] && ans == K_NONE; i++)
    {
        napms(TICK_MS);
        int c = getch();
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
    }
    
    return ans;
}

state_t menuInit(void) {
    while(1) {
        system("clear");
        printf(""
            "  _____ ____    ____  __  _    ___ \n"
            " / ___/|    \\  /    ||  |/ ]  /  _]\n"
            "(   \\_ |  _  ||  o  ||  ' /  /  [_ \n"
            " \\__  ||  |  ||     ||    \\ |    _]\n"
            " /  \\ ||  |  ||  _  ||     \\|   [_ \n"
            " \\    ||  |  ||  |  ||  .  ||     |\n"
            "  \\___||__|__||__|__||__|\\_||_____|\n"
            "\n\n"
        );
        printf("Welcome. Insert 'p' to play, 's' to customize the settings and 'q' to quit:\n");
        int c = getchar(), aux = c;
        while(aux != '\n' && aux != EOF) aux = getchar(); // Clean buffer
        system("clear");
        //waits until sth is pressed
        switch(TOUPPER(c)) {
            case 'Q':
                return EXIT;
            case 'P':
                return PLAYING;
            case 'S':
                return MENU_SETTINGS;
        }

    }

}

void customizeSettings(game_settings_t* settings) {
    int flag = 0;
    system("clear");
    while(!flag) {
        printf(
            "Settings:\n"
            "Board width: %d\n"
            "Board height: %d\n"
            "Initial length: %u\n"
            "Speed: %d\n",
            settings->width, settings->height,settings->init_length, settings->speed
        );
        
        printf("Choose an option to change (w, h, l, s) or quit (q):\n");
        
        int c = getchar(), aux = c;
        while(aux != '\n' && aux != EOF) aux = getchar(); // Clean buffer
        system("clear");

        switch(TOUPPER(c)) {
            case 'W':
                getValue(&(settings->width), MIN_BOARD_SIZE, MAX_BOARD_SIZE, "board width");
                break;
            case 'H':
                getValue(&(settings->height), MIN_BOARD_SIZE, MAX_BOARD_SIZE, "board height");
                break;
            case 'L':
                getValue((int*) &(settings->init_length), MIN_INIT_LEN, MIN(settings->width, settings->height)-2, "initial length");
                break;
            case 'S':
                getValue(&(settings->speed), 1, MAX_SPEED, "speed");
                break;
            case 'Q':
                flag = 1;
                break;
            default:
                break;
        }
        
    }

    return;

}

void getValue(int* value, int min, int max, const char name[]) {

    system("clear");
    int flag = 0, input;

    while(!flag) {
        printf("Current %s value: %d\n"
            "Please input new %s value (min. %d, max. %d) or q to quit:\n",
            name, *value, name, min, max );
        input = getInt(max+1);
        
        system("clear");
        
        // Validate input
        if(input == 0) { // 'q' inputted
            flag = 1;
        } // Incorrect input
        else if(input < 0 || input < min || input > max) {
            printf("Error with input or range of values\n");
            flag = 0;
        } else { // Correct input
            *value = input;
            flag = 0;
        }
    }

    return;
}

int getInt(int max)
{
    int i, num = 0;
    char c = getchar();
    if(TOUPPER(c) == 'Q') return 0;

    for(i = 0; c !='\n' && i < max; i++, c=getchar())
    {
        if(c < '0' || c > '9') return INPUT_ERR;
        num = num*10 + (c-'0');
    }
    while(c != '\n') c = getchar(); // Clean stdin buffer

    return (num == 0) ? INPUT_ERR : num;

}
