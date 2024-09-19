#ifndef PROGSTATES_H
#define PROGSTATES_H

#include "body.h" // type direction_t

typedef enum {
    PLAYING,
    PAUSE,
    GAMEOVER,
    MENU_INIT,
    MENU_SETTINGS,
    EXIT
} state_t;


typedef struct {
    int width;
    int height;
    int speed;
    int lives;
    int ticks_per_gametick;

    int init_x;
    int init_y;
    direction_t init_orient;
    unsigned init_length;

} game_settings_t;

#define DEFAULT_SETTINGS {.width=20, .height=20, .speed=1, .lives=3, .init_x=10, .init_y=10, .init_orient=N, init_length=3}

#endif // PROGSTATES_H