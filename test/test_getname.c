// gcc test/test_getname.c src/inputs.c -o build/test_inputs -Wall -Wextra -lncurses

#include <stdio.h>
#include <stdlib.h>
#include "../src/inputs.h"
#include "../src/consts.h"
#include <stdio.h>

#define TIMEOUT 300

int main(void)
{
    char name[NAME_MAX+1];
    getName(name);

    printf("Hola");
    getchar();
    
    return 0;
}