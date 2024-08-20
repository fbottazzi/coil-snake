#include <time.h>
#include "body.h"
#include "consts.h"
#include <stdio.h>

#include "game_rules.h"




//getName

void getName(char* name)
{
    int i;
    printf("please input name)");//I think it works, needs testing
    for(i=0;i<NAME_MAX&&name[i]!='\n';i++)
    {
        name[i]=getchar();
    }
    return;
}