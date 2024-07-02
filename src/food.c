#include <stdlib.h>//must test, Must create func freefood
#include <stdio.h>
#include <time.h>
#include "body.h"
#include "boardSize.h"
#include "food.h"






food_t* newFood(part_t* phead, int snakeSize)
{
    int i;
    food_t* p2Food=malloc(sizeof(food_t));
    if(p2Food==NULL)    return NULL;
    if(phead==NULL)     return NULL;
    part_t* aux=phead;
    coords_t* arrCoords=calloc(snakeSize,coords_t);
    //if(arrCoords==NULL)     return NULL; i think it will always be detected as NULL
    for(i=0;aux->p2next!=NULL;i++)
    {
        arrCoords+i=aux->coords;
        aux=aux->p2next;
    }
    p2Food->symbol='+';
    srand(time(NULL));


    for(i=0;i<(snakeSize-1);)
    {
        (p2Food->coords).x=rand()%B_ROW;//also works with COL
        (p2Food->coords).y=rand()%B_ROW;
        for(i=0;i<snakeSize&&((p2Food->coords).x!=(arrCoords+i)||(p2Food->coords).y!=(arrCoords+i));i++)
        {}
    }
    return p2Food;
}

