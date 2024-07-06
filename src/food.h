
typedef struct{
    int x;
    int y;
    char symbol;
}food_t;


food_t* newFood(part_t* phead, int snakeSize);
int foodEaten(food_t* p2Food, int snakeSize);