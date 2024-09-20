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

// Runs the game with the configuration from the structure
// Saves the information of the match in game_info
void runGame(game_settings_t* settings, gameinfo_t* game_info);

// Creates a random initial position (x, y) and random initial direction
void getRandPos(game_settings_t* settings);

#endif // GAME_RULES_H