#include "freeAny.h"
void freeAny(void*px, int size, int num)
{
    int i;
    for(i=0;i<size*num; i++)
    {
        free(((char*)px)+i);
    }
}