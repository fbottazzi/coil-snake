#ifndef INPUTS_H
#define INPUTS_H

#include "body.h"

typedef enum {
    K_UP = N,
    K_LEFT = W,
    // 0,
    K_RIGHT = E,
    K_DOWN = S,
    K_PAUSE,
    K_NONE

} input_t;



void getName (char* name);

// Checks for key input, returns NONE if
// neither the WASD/arrow keys nor the pause key have been pressed
input_t getKey(void);

#endif // INPUTS_H