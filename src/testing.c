#include <stdio.h> //just testing modify as you please
#include "coords.h"
#include "body.h"
#include  "food.h"

int main(void)
{
    part_t head;
    part_t* pHead=&head;
    initSnake(pHead);
    printf("%d\n",head.orient);
    printf("%d, %d\n",head.coords.x,head.coords.y);
    printf("%c\n",head.symbol);
    int snakeLen =1;
    food_t* foodItem =  newFood(pHead,snakeLen);
    printf("%p\n",foodItem);
    //printf("%d, %d\n",(foodItem->coords).x,(foodItem->coords).y);
    printf("%c\n",foodItem->symbol);
    snakeLen= foodEaten(foodItem,snakeLen);
    printf("%d\n",snakeLen);
}