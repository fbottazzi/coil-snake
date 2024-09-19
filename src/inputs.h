#ifndef INPUTS_H
#define INPUTS_H

#include "body.h"
#include "consts.h"
#include "game_rules.h"

#define MAX_DIG 3
#define GETNAME_DELAY_MS 2000


typedef enum {
    K_UP = N,
    K_LEFT = W,
    // 0,
    K_RIGHT = E,
    K_DOWN = S,
    K_PAUSE,
    K_NONE

} input_t;



void getNameandLength (char* name,game_settings_t* game_settings);
void getLength(game_settings_t* thisgame);
int getInt(void);
void getBoardSize(game_settings_t* thisGame);

// Checks for key input, returns NONE if
// neither the WASD/arrow keys nor the pause key have been pressed
input_t getInput(int _timeout);

#endif // INPUTS_H