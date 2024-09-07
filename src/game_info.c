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
        
    }
    return;
}





void storeGame(gameInfo* thisGame, snake_t* snake)
{
    //creates/opens the file
    FILE* gameFile = fopen("build/scores", "a+");
    int i;

    if(gameFile==NULL)//checks if some error ocurred
    {
        return;
    }

    //prints the name in the file
    fprintf(gameFile, "%s",thisGame->name);

    //assigns the score
    thisGame->score=snake->size;

    //prints the score
    fprintf(gameFile, "; %d; ",thisGame->score);

    //always ends in a new line and prints the date
    fprintf(gameFile,"%s \n", __DATE__);

    //closes file and commits the buffer
    fclose(gameFile);
    return;

}