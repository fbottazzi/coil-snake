#ifndef GAMEINFO
#define GAMEINFO

#include <stdlib.h>
#include "body.h"

#define NAME_MAX 8
#define NAME_ERR -8
#define CHARS_IN_DATE 9


typedef struct{
    char name[NAME_MAX];
    unsigned int score;
    

}gameInfo_t;


//functions definitions
void getName (char* name);
void storeGame(gameInfo_t* thisGame);

#endif





