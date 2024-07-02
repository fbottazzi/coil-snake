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
    (part->coords).x=BC_X;//taking into account a matrix of 10x10
    (part->coords).y=BC_Y;
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
        (pPart->coords).y+=1;//goes up
        break;
    case S:
        (pPart->coords).y-=1;//goes down
        break;
    case E:
        (pPart->coords).y+=1;//goes right 
        break;
    case W:
        (pPart->coords).y-=1;// goes left
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