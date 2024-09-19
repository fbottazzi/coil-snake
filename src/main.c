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
    //state_t gamestate = MENU_INIT;

    // At initialization: get the username
    getName(game_information.name);

    // Be able to select some settings
    customizeSettings(&settings);

    // Play with the selected settings and save the results in "game_information"
    runGame(&settings, &game_information);

    // Save game in history log
    storeGame(&game_information);
    
    return 0;
}