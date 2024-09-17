#include "game_info.h"
#include "consts.h"

#include <stdio.h>

#define HISTORY_LOG_ROUTE "build/scores"

//still have to make struct with data and the storage in a file

int storeGame(const gameinfo_t* this_game)
{
    // creates/opens the file
    FILE* games_file = fopen(HISTORY_LOG_ROUTE, "a+");
    if(games_file==NULL) return FILE_ERR;

    // Print name, score in the file in new line
    int i = 0;
    if(i >= 0) i = fprintf(games_file, "%s", this_game->name);
    if(i >= 0) i = fprintf(games_file, "; %d", this_game->score);
    if(i >= 0) i = fprintf(games_file, "\n"); // Use line break as terminator

    // Close file and commit the buffer
    fclose(games_file);
    return (i < 0) ? FILE_ERR : 0;

}