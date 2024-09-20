#include <ncurses.h> // Linux graphic library
#include <stddef.h> // NULL definition
#include "consts.h" // Error codes

#include "graphics.h" // Includes body, food & ncurses

/* ================ */
/* Constants & globals */

#define Y_0 8 // Min value: 2
#define X_0 2

#define DELAY_MS_AFTER_SNAKE_PRINT 800
#define DELAY_MS_FOR_CURSSET_ENABLE 500

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

void initGraphics(void) {
    
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    cbreak();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);

}

int printGameInit(int width, int height) {
    if(width < 0 || height < 0)    return INPUT_ERR;
    
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

    move(Y_0+height+1, X_0-1); // For testing purposes
    refresh();
    return 0;

}


void printSnake(const snake_t* snake, const food_t* food) {

    // Print the snake
    DRAWCOORD(snake->head, symbols[HEAD]);
    DRAWCOORD(snake->tail, symbols[TAIL]);

    const part_t* part;
    for(part = snake->head->p2next; part != NULL; part = part->p2next) {
        DRAWCOORD(part, symbols[BODY]);
    }
    
    printInBoard(NULL, NULL, food);
    refresh();
    napms(DELAY_MS_AFTER_SNAKE_PRINT);

}


void printHeader(int score, int lives)
{
    mvprintw(Y_0-2, X_0, "Score: %*d   Lives: %d", SCORE_WIDTH, score < MAX_SCORE ? score : MAX_SCORE, lives);
    refresh();
}

void eraseInBoard(int x, int y) {
    mvprintw(Y_0 + y, X_0 + x, "%s", symbols[NONE]);
    refresh();
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

    refresh();

}

state_t printPause(const snake_t* snake, const food_t* food, const game_settings_t* settings) {

    clear();

    int c;
    state_t ans = EXIT;

    mvprintw(Y_0, 0,
" _______  _______  __   __  _______  _______ \n"
"|       ||   _   ||  | |  ||       ||       |\n"
"|    _  ||  |_|  ||  | |  ||  _____||    ___|\n"
"|   |_| ||       ||  |_|  || |_____ |   |___ \n"
"|    ___||       ||       ||_____  ||    ___|\n"
"|   |    |   _   ||       | _____| ||   |___ \n"
"|___|    |__| |__||_______||_______||_______|\n"
        "Press 'p' to continue, \n"
        "press 'Q' to quit the game. \n"
    );
    //fuente: https://patorjk.com/software/taag/#p=testall&f=Big%20Money-nw&t=PAUSE

    refresh();

    napms(DELAY_MS_FOR_CURSSET_ENABLE);

    while(ans == EXIT) {
        c = getch();
        
        switch(c) {
            case 'Q':
            case 'q':
                return GAMEOVER;
            case 'P':
            case 'p':
                ans = PLAYING;
                break;
            default:
                ans = EXIT;
                break;
        }
    }
    flushinp();

    clear();

    printSnake(snake, food);
    printGameInit(settings->width, settings->height);

    refresh();
    return ans;
}

void eraseSnake(const snake_t* snake, int reprintwall) {
    
    const part_t* part;
    for(part = snake->head; part != NULL; part = part->p2next) {
        eraseInBoard(part->x, part->y);
    }
    if(reprintwall) DRAWCOORD(snake->head, symbols[WALL]);
    refresh();

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
    "Press any key to go back to main menu \n"
    );
    refresh();

    napms(DELAY_MS_FOR_CURSSET_ENABLE);

    nodelay(stdscr, FALSE);
    nocbreak();
    curs_set(TRUE);
    flushinp();

    getch();
    flushinp();
    
    clear();
    return;
    // Fuente https://patorjk.com/software/taag/#p=testall&f=Graffiti&t=GAME%20OVER
}

void printErrorMessage(int error_code) {
    clear();
    printw("\n\nError ocurred with error code %d. Press any key to go back to main menu\n\n", error_code);
    refresh();
    
    napms(DELAY_MS_FOR_CURSSET_ENABLE);
    curs_set(TRUE);
    timeout(-1);
    getch();
    
    flushinp();
    clear();
    return;
}