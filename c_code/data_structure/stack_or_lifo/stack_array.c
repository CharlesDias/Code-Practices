/*
Link: https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/

Basic operations on stack:

- push to insert an element into the stack.
- pop to remove a element from the stack.
- peek to return the element on the top of the stack.
- is_empty to return true if the stack is empty or false, otherwise.
- is_full to return true if the stack is full or false, otherwise.

NOTE: 
Memory leak analysis.

1. Install the Valgrind on Ubuntu.
2. Access the repository folder.
3. Compile the project and runs the command below.

valgrind --leak-check=full -v ./c_code/data_structure/stack_or_lifo/stack_array

The expected output is

...
==8783== All heap blocks were freed -- no leaks are possible
==8783== 
==8783== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct {
    unsigned int capacity;
    int top;
    int *array;
}stack_t;

stack_t* STACK_create(unsigned int capacity);
void STACK_delete(stack_t* me);
bool STACK_is_empty(stack_t *me);
bool STACK_is_full(stack_t *me);
bool STACK_push(stack_t *me, int value);
bool STACK_pop(stack_t *me, int *value);
bool STACK_peek(stack_t *me, int *value);

int main(int argc, char** argv)
{
   const unsigned int capacity = 32;
   stack_t *s1 = STACK_create(capacity);

   if(s1 == NULL)
   {
      puts("Creation stack failed!");
      exit(1);
   }

    printf("Stack is empty? %s\n", STACK_is_empty(s1) ? "true" : "false");
    printf("Stack is full?  %s\n\n", STACK_is_full(s1) ? "true" : "false");

    for(int index = 0; index < capacity; index++)
    {
        STACK_push(s1, index + 1);
    }

    int temp;
    STACK_peek(s1, &temp);
    printf("TOP is equal to %d\n", temp);
    printf("Stack is empty? %s\n", STACK_is_empty(s1) ? "true" : "false");
    printf("Stack is full?  %s\n\n", STACK_is_full(s1) ? "true" : "false");


    for(int index = 0; index < capacity; index++)
    {
        STACK_pop(s1, &temp);
        printf("POP %2d = %2d\n", index, temp);
    }

    printf("Stack is empty? %s\n", STACK_is_empty(s1) ? "true" : "false");
    printf("Stack is full?  %s\n\n", STACK_is_full(s1) ? "true" : "false");

    STACK_delete(s1);

    puts("");
    return 0;
}

stack_t* STACK_create(unsigned int capacity)
{
    assert(capacity != 0);

    stack_t *me = (stack_t *)malloc(sizeof(stack_t));
    if(me == NULL)
    {
        return NULL;
    }

    me->array = (int *)calloc(capacity, sizeof(int));

    if(me->array == NULL)
    {
        free(me);
        return NULL;
    }
    me->capacity = capacity;
    me->top = -1;
    return me;
}

void STACK_delete(stack_t *me)
{
    assert(me != NULL);

    free(me->array);
    free(me);
}

bool STACK_is_empty(stack_t *me)
{
    assert(me != NULL);

    return me->top == -1;
}

bool STACK_is_full(stack_t *me)
{
    assert(me != NULL);

    return me->top == me->capacity - 1;
}

bool STACK_push(stack_t *me, int value)
{
    assert(me != NULL);

    if(STACK_is_full(me))
    {
        return false;
    }
    me->array[++(me->top)] = value;
    return true;
}

bool STACK_pop(stack_t *me, int *value)
{
    assert(me != NULL);

    if(STACK_is_empty(me))
    {
        return false;
    }
    *value = me->array[me->top];
    me->top--;
    return true;
}

bool STACK_peek(stack_t *me, int *value)
{
    assert(me != NULL);

    if(STACK_is_empty(me))
    {
        return false;
    }
    *value = me->array[me->top];
    return true;
}