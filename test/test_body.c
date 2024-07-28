/* Terminal command:
gcc test/test_body.c src/body.c -o test/test_body
./test/test_body
*/

#include <stdio.h>
#include "../src/body.h"

#define CHECK_INSIDE_SNAKE(x, y) ( printf("(" #x ", " #y ") %s inside the snake\n", isInsideSnake((x), (y), test_snake.head) ? "is" : "isn't" ) )

void printNodeList(const part_t* ptr);

int main(void)
{
    snake_t test_snake = {.head = NULL};
    // initialize head not to have problem with freeAll on a heap error

    // Testing initSnake
    printf("Running initSnake\n");
    if( initSnake(&test_snake, 4, 5, N) < 0) {
        printf("Heap error\n");
    }
    printNodeList(test_snake.head);
    printf("Value of test_snake.size: %d\n", test_snake.size);
    
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

void printNodeList(const part_t* ptr) {
    unsigned int i;
    char orient_chars[] = "NSEW";
    for(i = 0; ptr != NULL; i++) {
        printf("%3d: coords (%2d, %2d), orient %c\n", i, ptr->x, ptr->y,orient_chars[ ptr->orient ] );
        ptr = ptr->p2next;
    }

    printf("\nList size: %d\n", i);
}