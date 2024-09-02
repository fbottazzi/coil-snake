#ifndef GAMEINFO
#define GAMEINFO

#include <stdlib.h>

#define NAME_MAX 8
#define NAME_ERR -8

typedef struct{
    int day;
    int month;
    int year;
}date;

typedef struct{
    char name[NAME_MAX];
    unsigned int score;
    date gameDate;

} gameInfo;

void getName (gameInfo* thisGame);
void storeGame(gameInfo* thisGame);

#endif





