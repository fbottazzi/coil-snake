// gcc src/game_rules.c src/game_info.c src/inputs.c src/graphics.c src/body.c src/food.c test/test_game.c -o build/test_game -lncurses

#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include "../src/game_rules.h"
#include "../src/consts.h"
#include "../src/progstates.h"
#include "../src/game_info.h"
#include "../src/inputs.h"

#define TIMEOUT 15


int main(void) {

    srand(time(NULL));
    
    game_settings_t settings = {
        .width = B_COL, .height = B_ROW,
        ._timeout = TIMEOUT, .lives = 3,
        .init_x = BC_X+5, .init_y = BC_Y-5, .init_orient = N, .init_length = 6
    };
    
    gameinfo_t game_info;
    getNameandLength(game_info.name, &settings);
    
    runGame(&settings, &game_info);

    storeGame(&game_info);

    return 0;

}