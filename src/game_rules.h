#ifndef GAME_RULES_H
#define GAME_RULES_H

#include "body.h"
#include "food.h"

typedef enum {
    K_UP = N,
    K_LEFT = W,
    // 0,
    K_RIGHT = E,
    K_DOWN = S,
    K_PAUSE,
    K_NONE

} key_t;

// Checks for key input during time_in_ms miliseconds,
// Returns NONE if neither the WASD/arrow keys nor the pause key's been pressed
key_t getInputInTimeout(unsigned int time_in_ms);

// Boolean comparison that returns 1 if the head is inside the border or a body part
#define COLLISION(phead, width, height) ( \
    (phead)->x < 0 || (phead)->y < 0 || \
    (phead)->x >= (width) || (phead)->y >= (height) || \
    isInsideSnake((phead)->x, (phead)->y, phead) \
)


#endif // GAME_RULES_H