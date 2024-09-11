#include <ncurses.h> // Linux graphic library
#include <stddef.h> // NULL definition
#include "consts.h" // Error codes

#include "graphics.h" // Includes body, food & ncurses
#include "progstates.h"

/* ================ */
/* Constants & globals */

#define Y_0 8
#define X_0 2

enum {
    NONE = 0,
    WALL,
    HEAD,
    BODY,
    TAIL,
    FOOD,
    SYMBOLS_SIZE
};

const char* symbols[] = { 
    " ", // NONE    
    "#", // WALL    
    "S", // HEAD    
    "o", // BODY    
    "-",  // TAIL    
    "X", // FOOD
    "" // Terminador
};



/* ====== */
/* Macros */

#define DRAWCOORD(point, symbol) ( mvprintw( Y_0 + (point)->y, X_0 + (point)->x, "%s", symbol ) )

/* ========= */
/* Functions */

void initGraphics(int _timeout) {

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    cbreak();
    curs_set(FALSE);
    timeout(_timeout);

}

int printGameInit(const snake_t* snake, int width, int height) {
    if(snake == NULL || width < 0 || height < 0)    return INPUT_ERR;
    
    int i;

    // Top wall
    move(Y_0-1, X_0-1);
    for(i = 0; i < width+2; i++) {
        printw("%s", symbols[WALL]);
    }
    
    // Bottom wall
    move(Y_0+height, X_0-1);
    for(i = 0; i < width+2; i++) {
        printw("%s", symbols[WALL]);
    }

    // Left & right walls
    for(i = Y_0; i < Y_0+height; i++) {
        mvprintw(i, X_0-1, "%s", symbols[WALL]);
        mvprintw(i, X_0+width, "%s", symbols[WALL]);
    }

    // Snake
    // printSnake(snake);

    move(Y_0+height+1, X_0-1); // For testing purposes
    return 0;

}

void printSnake(const snake_t* snake) {

    DRAWCOORD(snake->head, symbols[HEAD]);
    DRAWCOORD(snake->tail, symbols[TAIL]);

    const part_t* part;
    for(part = snake->head->p2next; part != NULL; part = part->p2next) {
        DRAWCOORD(part, symbols[BODY]);
    }

}

void eraseSnake(const snake_t* snake, int reprintwall) {
    
    const part_t* part;
    for(part = snake->head; part != NULL; part = part->p2next) {
        eraseInBoard(part->x, part->y);
    }
    if(reprintwall) DRAWCOORD(snake->head, symbols[WALL]);

}

void eraseInBoard(int x, int y) {
    mvprintw(Y_0 + y, X_0 + x, "%s", symbols[NONE]);
}

void printInBoard(const part_t* head, const part_t* tail, const food_t* food) {
    if(tail != NULL) {
        DRAWCOORD(tail, symbols[TAIL]);
    }

    if(food != NULL) {
        DRAWCOORD(food, symbols[FOOD]);
    }

    if(head != NULL) {
        DRAWCOORD(head->p2next, symbols[BODY]);
        DRAWCOORD(head, symbols[HEAD]);
    }


}

void printGameOver(void) {
    clear();

    printw(
    " _______  _______  __   __  _______    _______  __   __  _______  ______   \n"
    "|       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |  \n"
    "|    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||  \n"
    "|   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_ \n"
    "|   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  |\n"
    "|   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | |\n"
    "|_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_|\n"
    "\n\n\n"
    "Press any key to go back to main menu "
    );

    curs_set(TRUE);
    timeout(-1);    

    while( getch() != '\n')    ;

    clear();
    return;
    // Fuente https://patorjk.com/software/taag/#p=testall&f=Graffiti&t=GAME%20OVER
}
