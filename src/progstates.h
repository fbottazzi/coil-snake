#ifndef PROGSTATES_H
#define PROGSTATES_H

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
    int _timeout;
    int lives;

    int init_x;
    int init_y;
    direction_t init_orient;
    unsigned init_length;

} game_settings_t;

#define DEFAULT_SETTINGS {20, 20, 500, 3, 10, 10, N, 3}

#endif // PROGSTATES_H