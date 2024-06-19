#include <stdio.h>
#define MAX_SIZE 255


struct QueueCharTag 
{
    int size;
    int head;
    int tail;
    char queueVal[MAX_SIZE];
};

typedef struct QueueCharTag QueueCharType;

QueueCharType createCharQueue()
{
    QueueCharType initial;
    initial.size = 0;
    initial.head = -1;
    initial.tail = 0;
    initial.queueVal[0] = 0;

    return initial;
}

int isQueueCharEmpty(QueueCharType Q)
{
    return Q.size == 0;
}

int isQueueCharFull(QueueCharType Q)
{
    return Q.size == MAX_SIZE;
}

int headChar(QueueCharType *Q)
{
    return Q->head;
}

int tailChar(QueueCharType *Q)
{
    return Q->tail;
}

int enqueueChar(QueueCharType *Q, char elem)
{
    int enqueued = 0;

    if (!isQueueCharFull(*Q))
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

int dequeueChar(QueueCharType *Q)
{
    char dequeueElem = '\0';

    if (!isQueueCharEmpty(*Q))
    {
        dequeueElem = Q->queueVal[Q->head];
        Q->head += 1;
        Q->size -= 1;
    }

    return dequeueElem;
}

void dispCharQueue(QueueCharType Q)
{
    int i;
    printf("<Queue>{");

    for (i = Q.head; i < Q.tail; i++)
    {
        printf("%c", Q.queueVal[i]);
        if (i != Q.tail-1)
            printf(", ");
    }
    printf("}\n");

}

// int main()
// {
//     QueueCharType Q;
//     Q = createQueue();

//     enqueue(&Q, '+');
//     enqueue(&Q, '-');
//     enqueue(&Q, '+');

//     dispQueue(Q);
//     printf("%c", dequeue(&Q));
//     printf("h %d %d %c", head(&Q), tail(&Q), Q.queueVal[1]);
//     // enqueue(&Q, 7);
//     // enqueue(&Q, 7);

//     dispQueue(Q);

//     return 0;
// }