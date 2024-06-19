// This module file contains the declarations for the attributes of a Queue data structure.

#define MAX_SIZE_QUEUE 255 * 2

struct queueTag 
{
    int  size;
    int  head;
    int  tail;
    char list[MAX_SIZE_QUEUE];
};

typedef struct queueTag Queue;