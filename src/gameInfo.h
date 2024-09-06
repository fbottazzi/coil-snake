#ifndef GAMEINFO
#define GAMEINFO

#include <stdlib.h>

#define NAME_MAX 8
#define NAME_ERR -8
#define CHARS_IN_DATE 9


typedef struct{
    char name[NAME_MAX];
    unsigned int score;
    

} gameInfo;

void getName (gameInfo* thisGame);
void storeGame(gameInfo* thisGame);

#endif





