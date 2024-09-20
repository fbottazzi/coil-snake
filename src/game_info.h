#ifndef GAMEINFO
#define GAMEINFO

#include <stdlib.h>
#include "body.h"
#include "consts.h"

/* ==================== */
/* Typedefs & Constants */

typedef struct{
    char name [NAME_MAX+1];
    int score;
    
} gameinfo_t;

#define HISTORY_LOG_ROUTE "./build/scores"


/* =================== */
/* Functions & Macros  */

int storeGame(const gameinfo_t* thisGame);

#endif





