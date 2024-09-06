#include "gameInfo.h"
#include <stdio.h>


//still have to make struct with data and the storage in a file
void getName (gameInfo* thisGame)
{
    printf("please input your name(max %d characters)", NAME_MAX);

    char c;
    int i;
    for(i=0; (c=getchar())!='\n' && i<NAME_MAX;i++)
    {
        (thisGame->name)[i] = c;
        printf("%c",c);
    }
    return;
}




//make typedef, needs testing
void storeGame(gameInfo* thisGame)
{
    FILE* gameFile = fopen("build/scores", "a+");
    int i;

    if(gameFile==NULL)
    {
        return;
    }

    for(i=0;i<NAME_MAX;i++)
    {
        fprintf(gameFile, "%c",thisGame->name[i]);
    }

    fprintf(gameFile, "; ");

    //always ends in a new line
    fprintf(gameFile, "%d; ",thisGame->score);

    fprintf(gameFile,"%s", __DATE__);

    fclose(gameFile);
    return;

}