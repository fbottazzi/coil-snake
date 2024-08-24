#ifndef GAME_RULES_H
#define GAME_RULES_H

#include "body.h"
#include "food.h"

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

} key_t;

// Boolean comparison that returns 1 if the head is inside the border or a body part
#define COLLISION(phead, width, height) ( \
    (phead)->x < 0 || (phead)->x >= (width) || \
    (phead)->y < 0 || (phead)->y >= (height) || \
    isInsideSnake((phead)->x, (phead)->y, phead) \
)


/* ======================= */
/* Functions */

// Checks for key input, returns NONE if
// neither the WASD/arrow keys nor the pause key have been pressed
key_t getKey(void);



#endif // GAME_RULES_H