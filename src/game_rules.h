#ifndef GAME_RULES_H
#define GAME_RULES_H

#include "body.h"
#include "food.h"
#include "progstates.h"
#include "game_info.h"



// Boolean comparison that returns 1 if the head is inside the border
#define WALLCOLLISION(phead, width, height) ( \
    (phead)->x < 0 || (phead)->x >= (width) || \
    (phead)->y < 0 || (phead)->y >= (height) \
)

/* ========= */
/* Functions */


void runGame(game_settings_t* settings, gameinfo_t* game_info);

int play(snake_t* snake, const game_settings_t* settings, int* score, int lives);

void getRandPos(game_settings_t* settings);

#endif // GAME_RULES_H