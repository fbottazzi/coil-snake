#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include "../src/game_rules.h"
#include "../src/body.h"
#include "../src/graphics.h"
#include "../src/food.h"
#include "../src/consts.h"
#include "../src/progstates.h"


#define TIMEOUT 300


int main(void) {

    srand(time(NULL));

    game_settings_t settings = {
        B_COL, B_ROW,
        TIMEOUT,
        BC_X+5, BC_Y-5, N, 6
    };
    runGame(&settings);

    return 0;

}