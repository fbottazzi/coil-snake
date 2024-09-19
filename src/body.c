#include <stdlib.h>
#include "consts.h"

#include "body.h"

int initSnake(snake_t* snake, int init_x, int init_y, direction_t init_orient, unsigned int init_length)
{
    // Allocate memory
    unsigned int i;
    snake->head = snake->tail = malloc(sizeof(part_t));
    if(snake->head == NULL)    return HEAP_ERR;

    // Only initialize the head because it's the same node as the tail
    snake->head->orient = init_orient;
    snake->head->x = init_x;
    snake->head->y = init_y;
    snake->head-> p2prev = snake->head->p2next = NULL;

    // Add init_length-1 nodes
    snake->time_since_growth = 0;
    snake->size = 1;
    for (i = 0; i < init_length-1; i++)
    {
        if( newNode(snake) == HEAP_ERR )    return HEAP_ERR;
    }
    return 0;
}

int isInsideSnake(int x, int y, const part_t* phead) {
    const part_t* ptr;
    for(ptr = phead; ptr != NULL; ptr = ptr->p2next) {
        if(ptr->x == x && ptr->y == y) return 1;
    }

    return 0;
}

void update(snake_t* snake, direction_t dir) {

    if(dir == - snake->head->orient) { // Can't turn 180deg
        dir = -dir;         // Just don't turn
    }

    part_t *new_head = snake->tail, *new_tail = snake->tail->p2prev;
    // Instead of freeing the tail and allocating a new head,
    // I'll use the same space and interchange the values

    // "Move" current tail node to the head by changing the pointers
    new_tail->p2next = NULL;
    snake->head->p2prev = new_head;

    // Values of new_head
    new_head->orient = dir;
    new_head->p2next = snake->head;
    new_head->p2prev = NULL;
    
    // New position
    new_head->x = snake->head->x;
    new_head->y = snake->head->y;

    switch(dir) {
            case N:
                (new_head->y)--;
                break;
            case S:
                (new_head->y)++;
                break;
            case E:
                (new_head->x)++;
                break;
            case W:
                (new_head->x)--;
                break;
    }

    snake->head = new_head;
    snake->tail = new_tail;
    snake->time_since_growth ++;

}

int newNode(snake_t* snake) {
    // Memory allocation
    part_t* new_tail = malloc(sizeof(part_t));
    if(new_tail == NULL) return HEAP_ERR;

    //Assigning new values
    snake->tail->p2next = new_tail;
    
    new_tail->orient = snake->tail->orient;
    new_tail->p2prev = snake->tail;
    new_tail->p2next = NULL;

    // Assigning position to one forward of the current tail position
    new_tail->x = snake->tail->x;
    new_tail->y = snake->tail->y;
    switch(new_tail->orient) {
        case N:
            (new_tail->y)++;
            break;
        case S:
            (new_tail->y)--;
            break;
        case E:
            (new_tail->x)--;
            break;
        case W:
            (new_tail->x)++;
            break;
    }

    snake->tail = new_tail;
    (snake->size)++;
    return 0;
}

void freeAll(part_t* phead)
{
    if(phead == NULL)   return;

    part_t *current = phead, *next = phead->p2next;
    while(next != NULL) { // goes through the list until current is the last element
        free(current);
        current = next;
        next = current->p2next;
    }
    free(current);

}
