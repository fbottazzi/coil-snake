// 10.08: MUST TEST

#ifndef FOOD_H
#define FOOD_H


typedef struct {
    int x;
    int y;
    // clock_t time;
} food_t;

food_t newFood(const part_t* phead, int width, int height);
int checkFood(food_t* p2food, snake_t* snake, int width, int height);


#endif // FOOD_H