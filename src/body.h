// Structure definitions to save snake's body

typedef enum {
    N = 0, S , E , W
} direction_t;



typedef struct PART {
    direction_t orient;
    int x;
    int y;
    struct PART* p2next;
} part_t;

typedef struct {
    part_t* head;
    part_t* tail;
    int size;
} snake_t;

int initSnake(snake_t* snake, int init_x, int init_y, direction_t init_orient);
void freeAll(part_t* phead);
int isInsideSnake(int x, int y, const part_t* phead);

void newNode(part_t* pPart);
void update(part_t* pPart, int newDir);