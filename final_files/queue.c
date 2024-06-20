// This C file contains the implementations and definitions for the operations of a Queue data structure.

#include "queue.h" // Module file for a Queue data structure.

/* createQueue() creates an empty queue and returns it.
   @return the created empty queue.
*/
Queue
createQueue() 
{
    Queue queue;

    queue.size = MAX_SIZE_QUEUE;
    queue.head = 0;
    queue.tail = 0;
    queue.list[0] = '\0';
    
    return queue;
}

/* enqueue() inserts a character element into the given queue.
   @param queue - the address of the queue where the element will be inserted.
   @param token - the character element that will be inserted into the queue.
   Pre-condition/s: queue is not full.
*/
void
enqueue(Queue* queue, char token) 
{
    queue->list[queue->tail] = token;

    // Implementation of a circular queue.
    if (queue->tail + 1 != queue->size)
        queue->tail += 1;
    else
        queue->tail = 0;
}

/* dequeue() deletes the first element from the queue and returns it.
   @param queue - the address of the queue where the element will be deleted.
   @return the character element that was deleted from the queue.
   Pre-condition/s: queue is not empty.
*/
char
dequeue(Queue* queue) 
{
    char token = queue->list[queue->head];

    // Implementation of a circular queue.
    if (queue->head + 1 != queue->size)
        queue->head += 1;
    else
        queue->head = 0;
        
    return token;
}

/* getHead() returns the character element at the head of the queue.
   @param queue - the queue to be considered.
   @return the character element at the head of the queue.
*/
char
getHead(Queue queue) 
{
    char token = queue.list[queue.head];
    return token;
}

/* getTail() returns the character element at the tail of the queue.
   @param queue - the queue to be considered.
   @return the character element at the tail of the queue.
*/
char
getTail(Queue queue) 
{
    char token = queue.list[queue.tail];
    return token;
}

/* isQueueEmpty() checks if the given queue is empty or not.
   @param queue - the queue to be considered.
   @return 1 if the queue is empty and 0 if not.
*/
int
isQueueEmpty(Queue queue) 
{
    if (queue.head == queue.tail)
        return 1;
    else
        return 0;
}

/* isQueueFull() checks if the given queue is full or not.
   @param queue - the queue to be considered.
   @return 1 if the queue is full and 0 if not.
*/
int
isQueueFull(Queue queue) 
{
    if (queue.head == (queue.tail + 1) % queue.size)
        return 1;
    else
        return 0;
}