#include "coords.h"
#include <stdlib.h>
#include "body.h"
#include "boardSize.h"

#define INIT_LENGTH 3

int initSnake(snake_t* snake, int init_x, int init_y, direction_t init_orient)
{
    // Counters for the position of each part and the numbers of parts
    int i, x = init_x, y = init_y;
    part_t* part;
    snake->head = malloc(sizeof(part_t));
    
    // Give values to INIT_LENGTH-1 nodes (including the head), and reserving memory for the next node
    for(i = 0, part = snake->head; i < INIT_LENGTH-1 && part != NULL; i++) {

        // Give values to the current part
        part->x = x;
        part->y = y;
        part->orient = init_orient;
        part->p2next = malloc(sizeof(part_t));

        // Update values
        part = part->p2next;
        switch(init_orient) {
            // Update (x, y) contrary to the value of init_orient
            // because we start from the head
            case N:
                y++;
                break;
            case S:
                y--;
                break;
            case E:
                x--;
                break;
            case W:
                x++;
                break;
        }
    }
    // validate the memory allocation
    snake->size = i+1;
    if(part == NULL)    return -1;

    // Give values to the tail
    part->x = x;
    part->y = y;
    part->orient = init_orient;
    part->p2next = NULL;

    snake->tail = part;
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

int isInsideSnake(int x, int y, const part_t* phead) {
    const part_t* ptr;
    for(ptr = phead; ptr != NULL; ptr = ptr->p2next) {
        if(ptr->x == x && ptr->y == y) return 1;
    }

    return 0;
}

/* Falta retocar errores acá

void newNode(part_t* pPart)
{
    while(pPart->p2next!=NULL)
    {
        pPart=pPart->p2next;
    }
    pPart->p2next=malloc(sizeof(*pPart));//remember to free malloc
    part_t* pNew=pPart->p2next;
    if(pNew==NULL)
    {
        return;
    }
    pNew->symbol='*';
    pNew->p2next=NULL;
    switch (pPart->orient)
    {
    case N:
        (pPart->p2next)->y=(pPart->y)-1;//set it one tile behind so when it updates it goes to the last one
        (pPart->p2next)->x=(pPart->x);//i dont care about direction since i only need it to give it to the next one 
        break;
    case S:
        (pPart->p2next)->y=(pPart->y)+1;
        (pPart->p2next)->x=(pPart->x);
        break;
    case E:
        (pPart->p2next)->y=(pPart->y);
        (pPart->p2next)->x=(pPart->x)-1; 
        break;
    case W:
        (pPart->p2next)->y=(pPart->y);
        (pPart->p2next)->x=(pPart->x)+1;
        break;
    
    }
    return;
}

void update(part_t* pPart, int newDir)
{
    if(pPart==NULL)
    {
        return;
    }
    int oldDir = pPart->orient;
    pPart->orient=newDir;
    
    
    switch (newDir)
    {
    case N:
        pPart->y+=1;//goes up
        break;
    case S:
        pPart->y-=1;//goes down
        break;
    case E:
        pPart->x+=1;//goes right 
        break;
    case W:
        pPart->x-=1;// goes left
        break;
    
    }
    return update((pPart->p2next), oldDir);
    
}

*/