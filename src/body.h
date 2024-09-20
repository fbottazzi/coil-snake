/*
Body module:
- Manages the structures that save the snake's body
- Functions to initialize, move, let grow and check collisions
*/

#ifndef BODY_H
#define BODY_H


/* ==================== */
/* Typedefs & Constants */

typedef enum {
    N = -2, W = -1 , E = 1, S = 2
    // Meant for opposite directions to have opposite values
} direction_t;

// Each bodypart of the snake
typedef struct PART {
    direction_t orient;
    int x;
    int y;
    struct PART* p2prev;
    struct PART* p2next;
} part_t;

typedef struct {
    part_t* head;
    part_t* tail;
    int size;
    int time_since_growth; // time (in gameticks) passed since the last time the snake grew
} snake_t;


/* =================== */
/* Functions & Macros  */

// Initializes the snake with a certain initial position, orientation and length
// If some malloc fails, returns HEAP_ERR, otherwise, it returns 0
int initSnake(snake_t* snake, int init_x, int init_y, direction_t init_orient, unsigned int init_length);

// Boolean function: returns 1 if there’s a part of the snake in the position (x, y), 0 if not
int isInsideSnake(int x, int y, const part_t* phead);

// Moves the snake one step into the direction dir, not increasing it's size
// If dir is opposite to the head's orientation, ignores it and updates it forward
// Doesn't return any error code since it doesn't allocate memory on the heap
void update(snake_t* snake, direction_t dir);

// Creates a new part behind the tail and saves it in the snake as the new tail
// Allocates memory so it returns HEAP_ERR if it fails, 0 if it doesn't
int newNode(snake_t* snake);

// Frees the memory used for the snake on the heap
void freeAll(part_t* phead);


#endif // BODY_H