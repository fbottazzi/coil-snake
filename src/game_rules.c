#include <time.h>
#include "body.h"
#include "consts.h"
#include <stdio.h>

#include "game_rules.h"


int main(void)
{
    char name[NAME_MAX];
    getName(name);
    int a;
    for(a=0;a<3;a++)
    {
        printf("%c",*(name+a));
    }
    return 0;
}


//getName

void getName(char* name)
{
    int i;
    printf("please input Nickname (three characters)");//hay que hacerla funcionar y robussta
    for(i=0;i<NAME_MAX&&name[i]!='\n';i++)
    {
        name[i]=getchar();
    }
    return;
}