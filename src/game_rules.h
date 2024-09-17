#ifndef GAME_RULES_H
#define GAME_RULES_H

#include "body.h"
#include "food.h"
#include "progstates.h"
#include "game_info.h"



/* ======================= */
/* Macros & typedefs */

typedef struct {
    int width;
    int height;
    int _timeout;
    int lives;

    int init_x;
    int init_y;
    direction_t init_orient;
    unsigned init_length;

} game_settings_t;

// Boolean comparison that returns 1 if the head is inside the border
#define WALLCOLLISION(phead, width, height) ( \
    (phead)->x < 0 || (phead)->x >= (width) || \
    (phead)->y < 0 || (phead)->y >= (height) \
)

/* ========= */
/* Functions */


int runGame(const game_settings_t* settings);

state_t play(snake_t* snake, food_t* food, const game_settings_t* settings, int* score, int lives, gameinfo_t* thisGame);

#endif // GAME_RULES_H