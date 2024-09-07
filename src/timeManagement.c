#include "timeManagement.h"


void startTime(timeMan_t* time)
{
    time->start=SEG_CLOCK;
    return;
}

void timeMan(timeMan_t* time)
{
    clock_t aux;
    aux= (SEG_CLOCK)-time->start;
    while((aux)>SEG_X_MIN)
    {
        aux-=SEG_X_MIN;
        time->nowMin++;
        
    }
    time->nowSec = aux;
    return;

}