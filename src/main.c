#include <stdio.h>
#include <stdlib.h>
#include "game_rules.h"
#include "consts.h"

#define TIMEOUT 300

int main(void)
{

    runGame(B_COL, B_ROW, TIMEOUT, BC_X, BC_Y, N, 3);
    
    return 0;
}