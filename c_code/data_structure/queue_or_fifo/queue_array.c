/* Link: https://www.geeksforgeeks.org/introduction-to-queue-data-structure-and-algorithm-tutorials/

Basic operations for Queue:
1. Enqueue - Adds (or stores) an element to the end of the queue.
2. Dequeue - Removal of elements from the queue.
3. Peek() or front() - Acquires the data element available at the front node of the queue without deleting it.
4. Rear() - This operation returns the element at the rear end without removing it.
5. isFull() - Validates if the queue is full.
6. isEmpty() - Validates if the queue is empty.

NOTE: 
Memory leak analysis.

1. Install the Valgrind on Ubuntu.
2. Access the repository folder.
3. Compile the project and runs the command below.

valgrind --leak-check=full -v ./c_code/data_structure/queue_or_fifo/queue_array

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
    int front, rear, size;
    unsigned capacity;
    int *array;
}queue_t;

queue_t* QUEUE_create(unsigned capacity);
bool QUEUE_delete(queue_t *me);
bool QUEUE_is_empty(queue_t *me);
bool QUEUE_is_full(queue_t *me);
unsigned QUEUE_size(queue_t *me);
bool QUEUE_enqueue(queue_t *me, int value);
bool QUEUE_dequeue(queue_t *me, int *value);

void print_queue(queue_t *me)
{
    printf("Is the queue empty? %s\r\n", QUEUE_is_empty(me) ? "true" : "false");
    printf("Is the queue full?  %s\r\n", QUEUE_is_full(me) ? "true" : "false");
    printf("Queue size is %u\r\n\r\n", QUEUE_size(me));
}

void enqueue_all(queue_t *me)
{
    int value = 1;
    printf("Enqueue all:");
    while(!QUEUE_is_full(me))
    {
        printf(" %d", value);
        QUEUE_enqueue(me, value++);
    }
    puts("");
    puts("");
}

void dequeue_all(queue_t *me)
{
    int value = 0;
    printf("Dequeue all:");
    while(!QUEUE_is_empty(me))
    {
        QUEUE_dequeue(me, &value);
        printf(" %d", value);
    }
    puts("");
    puts("");
}

int main (int argc, char **argv) 
{
    queue_t *q;
    const int capacity = 8;
    q = QUEUE_create(capacity);

    print_queue(q);    
    enqueue_all(q);
    print_queue(q);
    dequeue_all(q);
    print_queue(q);

    QUEUE_delete(q);

    puts("");
    return 0;
}

queue_t* QUEUE_create(unsigned capacity)
{
    assert(capacity != 0);

    queue_t *me = (queue_t *)malloc(sizeof(queue_t));
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
    me->front = 0;
    me->rear = me->front;
    me->size = 0;

    return me;
}

bool QUEUE_delete(queue_t *me)
{
    assert(me != NULL);

    free(me->array);
    free(me);
}

bool QUEUE_is_empty(queue_t *me)
{
    assert(me != NULL);

    return me->size == 0;
}

bool QUEUE_is_full(queue_t *me)
{
    assert(me != NULL);

    return me->size == me->capacity;
}

unsigned QUEUE_size(queue_t *me)
{
    assert(me != NULL);

    return me->size;
}

bool QUEUE_enqueue(queue_t *me, int value)
{
    assert(me != NULL);

    if(QUEUE_is_full(me))
    {
        return false;
    }
    me->array[me->rear] = value;
    me->rear = (me->rear + 1) % me->capacity;
    me->size++;
    return true;
}

bool QUEUE_dequeue(queue_t *me, int *value)
{
    assert(me != NULL);

    if(QUEUE_is_empty(me))
    {
        return false;
    }

    *value = me->array[me->front];
    me->front = (me->front + 1) % me->capacity;
    me->size--;
    return true;
}