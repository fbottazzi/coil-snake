#include <stdio.h> //just testing modify as you wish
#include "coords.h"
#include "body.h"
#include  "food.h"

int main(void)
{
    part_t head;
    part_t* pHead=&head;
    initSnake(pHead);
    printf("%d\n",head.orient);
    printf("%d, %d\n",head.x,head.y);
    printf("%c\n",head.symbol);
    int snakeLen =1;
    food_t* foodItem =  newFood(pHead,snakeLen);

    printf("%d, %d\n",foodItem->x,foodItem->y);
    printf("%c\n",foodItem->symbol);

    snakeLen= foodEaten(foodItem,snakeLen);
    
    newNode(pHead);

    /*printf("%d\n",(head.p2next)->orient);
    printf("%d, %d\n",(head.p2next)->x,(head.p2next)->y);
    printf("%c\n",(head.p2next)->symbol);*/

    update(pHead,E);
    printf("%d\n",snakeLen);

    printf("%d\n",head.orient);
    printf("%d, %d\n",head.x,head.y);
    printf("%c\n",head.symbol);


    printf("%d\n",(head.p2next)->orient);
    printf("%d, %d\n",(head.p2next)->x,(head.p2next)->y);
    printf("%c\n",(head.p2next)->symbol);
}