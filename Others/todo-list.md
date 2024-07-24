# To-Do

* ~~Re-do the milestones activity and send it~~
* Write a makefile and command(s) in tasks.json to build the whole thing
(!!! objects and executables must be saved in build folder, .c and .h in src folder)
* Split the program/project in modules and decide which one will each person do

# (By Franco) Changes in code I would do

* We'll have to comment well the code in the moment we write it, or we'll probably DIE

## Body
* Structure part_t: 'enum direccion' has to be a datatype defined with typedef
* Function initSnake: BC_X and BC_Y should be passed as parameters to facilitate future modifications
* newNode and update: don't understand the usage / logic. Shouldn't we have 2 functions, one that "pushes" some part of the snake in the same direction that it has and other that creates a new part in the new direction?
(Ok i think i understand, you're trying to save each "pixel" of the snake, what I thought was to save each "corner", the head and the tail)

* Function newNode: we shouldn't always pass the first part to the function, but the last (in fact, a pointer to the last, to update it directly in the function)
* Function newNode: !!! hardcoded head & tail symbols
* Function newNode: in the switch, use 'pNew' instead of 'pPart->p2next'

## Collision & food
* The algorithm for checking if the coordinate is in the snake could be done by going through the node directly instead of copying everything to an array
* They could be a single module given that they have one function each and they could share a function to search if some coordinate is in the snake

## coords.h
* Shouldn't either this be in body.h, or use coords.h to include the part_t structure? (There are modules including "body.h" but not using any body.c function)

