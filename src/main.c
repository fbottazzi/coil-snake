#include <stdio.h>
#include <stdlib.h>
#include "game_rules.h"
#include "inputs.h"
#include "progstates.h"
#include "consts.h"

#include <stdio.h>

#define TIMEOUT 300

int main(void)
{
    game_settings_t settings;
    gameinfo_t game_information;
    state_t gamestate = MENU_INIT;

    while(gamestate != EXIT) {

        switch(gamestate) {
            case MENU_INIT:
                getNameandLength(game_information.name);
                // gamestate = getNextMenu();
                break;
            case PLAYING:
                runGame(&settings, &game_information);
        }

    }
    return 0;
}