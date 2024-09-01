#ifndef GAME_RULES_H
#define GAME_RULES_H

#include "body.h"
#include "food.h"
#include "progstates.h"

/* ======================= */
/* Macros & typedefs */

#define NAME_MAX 8

typedef enum {
    K_UP = N,
    K_LEFT = W,
    // 0,
    K_RIGHT = E,
    K_DOWN = S,
    K_PAUSE,
    K_NONE

} input_t;

// Boolean comparison that returns 1 if the head is inside the border or a body part
#define COLLISION(phead, width, height) ( \
    (phead)->x < 0 || (phead)->x >= (width) || \
    (phead)->y < 0 || (phead)->y >= (height) || \
    isInsideSnake((phead)->x, (phead)->y, (phead)->p2next) \
)

/* ======================= */
/* Functions */

// Checks for key input, returns NONE if
// neither the WASD/arrow keys nor the pause key have been pressed
input_t getKey(void);

int runGame(int width, int height, int gametick_ms, int init_x, int init_y, direction_t init_orient, unsigned int init_length);

#endif // GAME_RULES_H