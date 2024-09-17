// gcc src/game_rules.c test/test_game.c -o build/test_game -lncurses

#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include "../src/game_rules.h"
#include "../src/consts.h"
#include "../src/progstates.h"


#define TIMEOUT 300


int main(void) {

    srand(time(NULL));

    game_settings_t settings = {
        .width = B_COL, .height = B_ROW,
        ._timeout = TIMEOUT, .lives = 3,
        .init_x = BC_X+5, .init_y = BC_Y-5, .init_orient = N, .init_length = 6
    };
    gameinfo_t game_info;
    runGame(&settings, &game_info);

    return 0;

}