#ifndef GAME_RULES_H
#define GAME_RULES_H

#include "body.h"
#include "food.h"
#include "progstates.h"



/* ======================= */
/* Macros & typedefs */

typedef enum {
    K_UP = N,
    K_LEFT = W,
    // 0,
    K_RIGHT = E,
    K_DOWN = S,
    K_PAUSE,
    K_NONE

} input_t;

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

// Boolean comparison that returns 1 if the head is inside the border or a body part
#define WALLCOLLISION(phead, width, height) ( \
    (phead)->x < 0 || (phead)->x >= (width) || \
    (phead)->y < 0 || (phead)->y >= (height) \
)

/* ========= */
/* Functions */

// Checks for key input, returns NONE if
// neither the WASD/arrow keys nor the pause key have been pressed
input_t getKey(void);

int runGame(const game_settings_t* settings);

state_t play(snake_t* snake, food_t* food, const game_settings_t* settings, int* score);

#endif // GAME_RULES_H