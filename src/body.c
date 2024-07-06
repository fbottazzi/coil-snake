#include "coords.h"
#include <stdio.h>
#include <stdlib.h>
#include "body.h"
#include "boardSize.h"

/*int main(void)        TESTING
{
    part_t head;
    part_t* p2head=&head;
    initSnake(p2head);
    printf("%d\n",head.orient);
    printf("%d, %d\n",head.coords.x,head.coords.y);
    printf("%c\n",head.symbol);
    
    newNode(p2head);

    printf("%d\n",head.orient);
    printf("%d, %d\n",head.coords.x,head.coords.y);
    printf("%c\n",head.symbol);
    printf("%p\n", (p2head->p2next));

    update(p2head, -2);
    
    printf("%d\n",head.orient);
    printf("%d, %d\n",head.coords.x,head.coords.y);
    printf("%c\n",head.symbol);

    



}*/

void initSnake(part_t* part)
{
    part->orient=1;
    part->x=BC_X;//taking into account a matrix of 10x10
    part->y=BC_Y;
    part->symbol ='^';
    part->p2next=NULL;   
}

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
        return NULL;
    }
    pNew->symbol='*';
    pNew->p2next=NULL;
    switch (pPart->orient)
    {
    case N:
        pPart->y=(pPart->y-1);//set it one tile behind so when it updates it goes to the last one
        pPart->x=(pPart->x);//i dont care about direction since i only need it to give it to the next one 
        break;
    case S:
        pPart->y=(pPart->y+1);
        pPart->x=(pPart->x);
        break;
    case E:
        pPart->y=(pPart->y);
        pPart->x=(pPart->x)-1; 
        break;
    case W:
        pPart->y=(pPart->y);
        pPart->x=(pPart->x)+1;
        break;
    
    }
    return ;
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
        pPart->y+=1;//goes right 
        break;
    case W:
        pPart->y-=1;// goes left
        break;
    
    }
    return update((pPart->p2next), oldDir);
    
}
/* does not work, make it work..
void freeAll(part_t* phead)
{
    int i;
    part_t* aux=phead;
    while(phead->p2next!=NULL)
    {
        aux=aux->p2next;
    }
    for(i=0;i<sizeof(part_t);i++)
    {
        free(aux);
    }
    
}*/