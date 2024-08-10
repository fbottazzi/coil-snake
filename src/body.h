// Structure definitions to save snake's body

typedef enum {
    N = -2, W = -1 , E = 1, S = 2
} direction_t;

typedef struct PART {
    direction_t orient;
    int x;
    int y;
    struct PART* p2prev;
    struct PART* p2next;
} part_t;

typedef struct {
    part_t* head;
    part_t* tail;
    int size;
} snake_t;

int initSnake(snake_t* snake, int init_x, int init_y, direction_t init_orient, unsigned int init_length);
int isInsideSnake(int x, int y, const part_t* phead);
void update(snake_t* snake, direction_t dir);
int newNode(snake_t* snake);
void freeAll(part_t* phead);

/*
void newNode(part_t* pPart);
void update(part_t* pPart, int newDir);
*/