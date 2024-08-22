#include "../src/body.h"
#include "../src/game_rules.h"
#include "../src/graphics.h"
#include "../src/food.h"
#include "../src/consts.h"

#define TRY(function, err_code) if((function) == (err_code))    return (err_code)

void pause(void) { clear(); printw("Pause\n"); timeout(20000); getch(); return; }

int main(void)
{
    INITCURSES();

    snake_t snake;
    food_t food;
    key_t key;
    unsigned int lives;
    register int i;

    TRY( initSnake(&snake, BC_X, BC_Y, N, 3), HEAP_ERR );
    printGameInit(&snake, B_COL, B_ROW);

    while(1) {
        
        key = getInputInTimeout(200);
        switch(key) {
            case PAUSE:
                pause();
                break;
            case NONE:
                break;
            default:
                update(&snake, (direction_t) key);
                break;
        }

        if( COLLISION(snake.head, B_COL, B_ROW) )

    }



    return 0;
}
