#include "coords.h"
#include "body.h"
#include <stdlib.h>//must test
#include <time.h>
#include<stdio.h>

#include "boardSize.h"
#include "food.h"




food_t* newFood(part_t* phead, int snakeSize)
{
    int i;
    food_t* p2Food=malloc(sizeof(food_t));
    if(p2Food==NULL)    return NULL;
    if(phead==NULL)     return NULL;
    part_t* aux=phead;
    coords_t* arrCoords =calloc(snakeSize,sizeof(coords_t));
    if(arrCoords==NULL)     return NULL;
    for(i=0;aux->p2next!=NULL;i++)
    {
        (arrCoords+i)->x=aux->x;
        (arrCoords+i)->y=aux->y;
        aux=aux->p2next;
    }
    p2Food->symbol='+';
    srand(time(NULL));

    
    for(i=0;i<(snakeSize);)
    {
        p2Food->x=(rand()%B_COL);//i give a random value to the coordinates
        p2Food->y=(rand()%B_ROW);
        
        
        for(i=0;i<snakeSize&&(p2Food->x!=(arrCoords+i)->x||p2Food->y!=(arrCoords+i)->y);i++)
        {}//this for searches if the food spawned inside the snake
    }
    for(i=0;i<snakeSize*sizeof(coords_t);i++)//frees all the bytes used in the array of coordinates
    {
        free((char*)arrCoords+i);
    }
    
    return p2Food;//remember to free when used, done in foodEaten
}

int foodEaten(food_t* p2Food, int snakeSize)
{
    if(p2Food==NULL)    return (snakeSize-1);
    snakeSize++;
    int i;
    for(i=0;i<sizeof(food_t);i++)
    {
        free(((char*)p2Food)+i);
    }
    return snakeSize;
}



