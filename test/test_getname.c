// gcc test/test_getname.c src/inputs.c -o build/test_inputs -Wall -Wextra -lncurses

#include <stdio.h>
#include "time.h"
// #include "../src/inputs.h"
// #include "../src/consts.h"
#include "../src/progstates.h"
#include "../src/inputs.h"

#define TIMEOUT 300

int main(void)
{
    game_settings_t settings = DEFAULT_SETTINGS;
    printf("Hola\n");
    customizeSettings(&settings);
    
    /*
    printf("Width: %d, height: %d, length: %d\n", settings.width, settings.height, settings.init_length);
    while(getchar() != '\n') ;
    system("clear");

    getValue(&(settings.width), MIN_BOARD_SIZE, MAX_BOARD_SIZE, "board width");
    */

    printf("Final values\nWidth: %d, height: %d, length: %d, speed: %d\n", settings.width, settings.height, settings.init_length, settings.speed);
    return 0;
}