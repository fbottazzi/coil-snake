enum direccion {
    N=1,S=-1,E=2,W=-2
}; //North, south, east, west; up, down,right, left




typedef struct PART {
    int orient;
    int x;
    int y;
    char symbol;
    struct PART* p2next;
} part_t;


void initSnake(part_t* part);
void newNode(part_t* pPart);
void update(part_t* pPart, int newDir);