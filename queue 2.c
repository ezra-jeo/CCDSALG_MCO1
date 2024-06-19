// This C file contains the implementations and definitions for the operations of a Queue data structure.

#include "queue.h"

Queue
createQueue () 
{
    Queue queue;

    queue.size = MAX_SIZE_QUEUE;
    queue.head = 0;
    queue.tail = 0;
    queue.list[0] = '\0';
    
    return queue;
}

void
enqueue (Queue* queue, char token) 
{
    queue->list[queue->tail] = token;

    if (queue->tail + 1 != queue->size)
        queue->tail += 1;
    else
        queue->tail = 0;
}

char
dequeue (Queue* queue) 
{
    char token = queue->list[queue->head];

    if (queue->head + 1 != queue->size)
        queue->head += 1;
    else
        queue->head = 0;
        
    return token;
}

char
head (Queue queue) 
{
    char token = queue.list[queue.head];
    return token;
}

char
tail (Queue queue) 
{
    char token = queue.list[queue.tail];
    return token;
}

int
queueEmpty (Queue queue) 
{
    if (queue.head == queue.tail)
        return 1;
    else
        return 0;
}

int
queueFull (Queue queue) 
{
    if (queue.head == (queue.tail + 1) % queue.size)
        return 1;
    else
        return 0;
}