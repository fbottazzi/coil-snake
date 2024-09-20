#ifndef GAMEINFO
#define GAMEINFO

#include <stdlib.h>
#include "body.h"
#include "consts.h"
#include <stdio.h>

#define HISTORY_LOG_ROUTE "./build/scores"

typedef struct{
    char name [NAME_MAX+1];
    int score;
    
} gameinfo_t;


//functions definitions
int storeGame(const gameinfo_t* thisGame);

#endif





