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
        (arrCoords+i)->x=(aux->coords).x;
        (arrCoords+i)->y=(aux->coords).y;
        aux=aux->p2next;
    }
    p2Food->symbol='+';
    srand(time(NULL));


    for(i=0;i<(snakeSize-1);)
    {
        (p2Food->coords).x=(rand()%10);//i give a random value to the coordinates
        (p2Food->coords).y=(rand()%B_ROW);
        
        for(i=0;i<snakeSize&&((p2Food->coords).x!=(arrCoords+i)->x||(p2Food->coords).y!=(arrCoords+i)->y);i++)
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



