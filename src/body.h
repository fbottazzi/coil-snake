enum direccion{
    N=1,S=-1,E=2,W=-2
};

typedef struct{
    int x;
    int y;
}coords_t;


typedef struct PART{
    int orient;
    coords_t coords;
    char symbol;
    struct PART* p2next;
}part_t;


void initSnake(part_t* part);
void newNode(part_t* pPart);
void update(part_t* pPart, int newDir);