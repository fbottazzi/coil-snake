typedef struct{
    coords_t coords;
    char symbol;
}food_t;


food_t* newFood(part_t* phead, int snakeSize);
void foodEaten(food_t* p2Food, int snakeSize);