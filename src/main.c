#include <stdio.h>
#include <stdlib.h>
// Backend
#include "game_rules.h"
#include "game_info.h"
#include "progstates.h"
// Frontend
#include "inputs.h"

#include <stdio.h>

#define TIMEOUT 300

int main(void)
{
    game_settings_t settings = DEFAULT_SETTINGS;
    gameinfo_t game_information;
    state_t gamestate = MENU_INIT;

    // At initialization: get the username
    getName(game_information.name);

    // Mini-finite state machine to control the program flow and menus
    while(gamestate != EXIT) {
        
        switch(gamestate) {
            case MENU_INIT:
                gamestate = menuInit();
                break;
            case PLAYING:
                runGame(&settings, &game_information);
                gamestate = GAMEOVER;
                break;
            case MENU_SETTINGS:
                customizeSettings(&settings);
                gamestate = MENU_INIT;
                break;
            case GAMEOVER:
                if( storeGame(&game_information) < 0) {
                    printf("Error at storing the file. Be sure to be executing the program in the right folder\n");
                    while( getchar() != '\n') ;
                    system("clear");
                }
                gamestate = MENU_INIT;
                break;
            case EXIT:
                system("clear");
                break;
        }

    }

    return 0;
}