#include "../src/gameInfo.h"
#include <stdio.h>


int main(void)
{
    gameInfo thisGame;
    gameInfo* pThisGame = &thisGame;

    getName(pThisGame);
    
    printf("%s \n",__DATE__);

    thisGame.score = 100;
    

    storeGame(pThisGame);
    return 0;

}