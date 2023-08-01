/*
Link: https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/

Basic operations on stack:

- push to insert an element into the stack.
- pop to remove a element from the stack.
- peek to return the element on the top of the stack.
- is_empty to return true if the stack is empty or false, otherwise.
- is_full to return true if the stack is full or false, otherwise.
- size to return the size of stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct {
    unsigned int size;
    int top;
    int *array;
}stack_t;

stack_t* STACK_create(unsigned int size);
void STACK_delete(stack_t* me);
bool STACK_is_empty(stack_t *me);
bool STACK_is_full(stack_t *me);
bool STACK_push(stack_t *me, int value);
bool STACK_pop(stack_t *me, int *value);
bool STACK_peek(stack_t *me, int *value);

int main(int argc, char** argv)
{
   const unsigned int size = 32;
   stack_t *s1 = STACK_create(size);

   if(s1 == NULL)
   {
      puts("Creation stack failed!");
      exit(1);
   }

    printf("Stack is empty? %s\n", STACK_is_empty(s1) ? "true" : "false");
    printf("Stack is full?  %s\n\n", STACK_is_full(s1) ? "true" : "false");

    for(int index = 0; index < size; index++)
    {
        STACK_push(s1, index + 1);
    }

    int temp;
    STACK_peek(s1, &temp);
    printf("TOP is equal to %d\n", temp);
    printf("Stack is empty? %s\n", STACK_is_empty(s1) ? "true" : "false");
    printf("Stack is full?  %s\n\n", STACK_is_full(s1) ? "true" : "false");


    for(int index = 0; index < size; index++)
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

stack_t* STACK_create(unsigned int size)
{
    assert(size != 0);

    stack_t *me = (stack_t *)malloc(sizeof(stack_t));
    if(me == NULL)
    {
        return NULL;
    }

    me->array = (int *)calloc(size, sizeof(int));

    if(me->array == NULL)
    {
        free(me);
        return NULL;
    }
    me->size = size;
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

    return me->top == me->size - 1;
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