#include "../src/gameInfo.h"
#include <stdio.h>


int main(void)
{
    gameInfo thisGame;
    gameInfo* pThisGame = &thisGame;

    getName(pThisGame);
    
    thisGame.score = 100;
    thisGame.gameDate.day =1;
    thisGame.gameDate.month =1;
    thisGame.gameDate.year =1;

    storeGame(pThisGame);
    return 0;

}