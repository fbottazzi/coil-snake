
typedef struct{
    int x;
    int y;
    // clock_t time;
}food_t;

food_t newFood(const part_t* phead, int board_width, int board_height);
int checkFood(food_t* p2food, snake_t* snake, unsigned int width, unsigned int height);