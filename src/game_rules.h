#ifndef GAME_RULES_H
#define GAME_RULES_H


#define COLLISION(phead, width, height) ( \
    (phead)->x < 0 || (phead)->y < 0 || \
    (pHead)->x >= (width) || (pHead)->y >= (height) || \
    isInsideSnake((phead)->x, (phead)->y, phead) \
)
#define NAME_MAX 3

void getName(char* name);

#endif // GAME_RULES_H