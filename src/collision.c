#include "coords.h"
#include "body.h"
#include "boardSize.h"
#include <stdlib.h>
#include "collision.h"
#include "coords.h"



int collision(part_t* pHead)
{
    if (pHead==NULL)    return ERROR;
    if(pHead->x<0||pHead->y<0||pHead->x>B_COL||pHead->y<B_ROW)  return COLLISION;
    part_t* aux;
    
    while
}