#include <time.h>
#include "body.h"
#include "consts.h"
#include <stdio.h>

#include "game_rules.h"

//getName

char* getName(void)
{
    int i;
    char nick[3];
    printf("please input Nickname (three characters)");
    for(i=0;i<NAME_MAX;i++)
    {
        nick[i]=getchar();
    }
    return nick;
}