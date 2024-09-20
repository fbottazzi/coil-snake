#ifndef INPUTS_H
#define INPUTS_H

#include "body.h"
#include "consts.h"
#include "progstates.h"

#define MIN_INIT_LEN 3
// Upper bound to init_length: board_size -1

#define MIN_BOARD_SIZE 5
#define MAX_BOARD_SIZE 60
#define MAX_BOARD_SIZE_DIGS 2


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


//gets username
void getName(char* name);

//gets an std input and turns it into an int
int getInt(int max_dig);


void getValue(int* value, int min, int max, const char name[]);


void customizeSettings(game_settings_t* settings);

state_t menuInit(void);
// Checks for key input, returns NONE if
// neither the WASD/arrow keys nor the pause key have been pressed
input_t getInput(int speed);

#endif // INPUTS_H