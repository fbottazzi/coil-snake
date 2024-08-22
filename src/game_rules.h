#ifndef GAME_RULES_H
#define GAME_RULES_H

#include "body.h"

typedef enum {
    UP = N,
    LEFT = W,
    // 0,
    RIGHT = E,
    DOWN = S,
    PAUSE,
    NONE

} key_t;

key_t getInputInTimeout(unsigned int time_in_ms);

#define COLLISION(phead, width, height) ( \
    (phead)->x < 0 || (phead)->y < 0 || \
    (pHead)->x >= (width) || (pHead)->y >= (height) || \
    isInsideSnake((phead)->x, (phead)->y, phead) \
)


#endif // GAME_RULES_H