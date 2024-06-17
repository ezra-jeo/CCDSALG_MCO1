#include <stdio.h>
#define MAX_SIZE 255


struct QueueTag 
{
    int size;
    int head;
    int tail;
    int queueVal[MAX_SIZE];
};

typedef struct QueueTag QueueType;

QueueType createQueue()
{
    QueueType initial;
    initial.size = 0;
    initial.head = -1;
    initial.tail = 0;
    initial.queueVal[0] = 0;

    return initial;
}

int isQueueEmpty(QueueType Q)
{
    return Q.size == 0;
}

int isQueueFull(QueueType Q)
{
    return Q.size == MAX_SIZE;
}

int head(QueueType *Q)
{
    return Q->head;
}

int tail(QueueType *Q)
{
    return Q->tail;
}

int enqueue(QueueType *Q, int elem)
{
    int enqueued = 0;

    if (!isQueueFull(*Q))
    {
        Q->queueVal[Q->tail] = elem;
        Q->size += 1;
        Q->tail += 1;
        
        if (Q->size == 1)
            Q->head = 0;
        enqueued = 1;
    }
    
    return enqueued;
    
}

int dequeue(QueueType *Q)
{
    int dequeueElem = 0;

    if (!isQueueEmpty(*Q))
    {
        dequeueElem = Q->queueVal[Q->head];
        Q->head += 1;
        Q->size -= 1;
    }

    return dequeueElem;
}

void dispQueue(QueueType Q)
{
    int i;
    printf("<Queue>{");

    for (i = Q.head; i < Q.tail; i++)
    {
        printf("%d", Q.queueVal[i]);
        if (i != Q.tail-1)
            printf(", ");
    }
    printf("}\n");

}

// int main()
// {
//     QueueType Q;
//     Q = createQueue();

//     enqueue(&Q, 5);
//     enqueue(&Q, 4);
//     enqueue(&Q, 3);

//     dispQueue(Q);
//     printf("%d", dequeue(&Q));
//     printf("h %d %d %d", head(&Q), tail(&Q), Q.queueVal[2]);
//     // enqueue(&Q, 7);
//     // enqueue(&Q, 7);

//     dispQueue(Q);

//     return 0;
// }