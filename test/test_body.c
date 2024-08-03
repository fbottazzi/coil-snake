/* Terminal command:
gcc test/test_body.c src/body.c -o test/test_body
./test/test_body
*/



/*

!!! Gotta re-test initSnake and test newNode

*/



#include <stdio.h>
#include "../src/body.h"
#define NEXT 0
#define PREV 1
const char aux[] = "NW ES", *dir_chars = &aux[2];

// Tests the function isInsideSnake and shows it on screen
#define CHECK_INSIDE_SNAKE(x, y) ( printf("(" #x ", " #y ") %s inside the snake\n", isInsideSnake((x), (y), test_snake.head) ? "is" : "isn't" ) )

// Goes through the snake nodes
// dir == NEXT (PREV) means going from head to tail (tail to head)
void printNodeList(const part_t* ptr, int dir);

// Executes the function update and shows it on screen
void runUpdate(snake_t *snake, direction_t dir);

int main(void)
{
    snake_t test_snake;

    // Testing initSnake
    printf("Running initSnake\n");
    if( initSnake(&test_snake, 4, 5, N, 3) < 0) {
        printf("Heap error\n");
    }
    printNodeList(test_snake.head, NEXT);
    printNodeList(test_snake.tail, PREV);
    printf("\nValue of test_snake.size: %d\n", test_snake.size);
    
    // Testing update
    printf("\nRunning update\n");
    runUpdate(&test_snake, N);
    runUpdate(&test_snake, E);

    // Testing isInsideSnake
    printf("\nRunning isInsideSnake\n");
    CHECK_INSIDE_SNAKE(4, 5);
    CHECK_INSIDE_SNAKE(4, 6);
    CHECK_INSIDE_SNAKE(4, 8);
    CHECK_INSIDE_SNAKE(5, 5);
    
    // Testing freeAll
    printf("\nRunning freeAll\n");
    freeAll(test_snake.head);
    printf("freeAll run without errors\n");

    return 0;
}

void printNodeList(const part_t* ptr, int dir) {
    unsigned int i;
    printf("Direction: %s\n", (dir == PREV) ? "tail to head" : "head to tail");
    for(i = 0; ptr != NULL; i++) {
        printf("%3d: coords (%2d, %2d), orient %c\n", i, ptr->x, ptr->y,dir_chars[ ptr->orient ] );
        ptr = (dir == PREV) ? ptr->p2prev : ptr->p2next;
    }

    printf("\nList size: %d\n", i);
}

void runUpdate(snake_t *snake, direction_t dir) {
    printf("Updating to direction %c\n", dir_chars[dir]);
    update(snake, dir);
    printNodeList(snake->head, NEXT);
}