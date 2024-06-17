#include <stdio.h>
#define MAX_SIZE 255

struct StackTag {
    int size;
    int stackVal[MAX_SIZE];
    int top;
};

typedef struct StackTag StackType;

StackType createStack()
{
    StackType initial;
    initial.size = 0;
    initial.stackVal[0] = 0;
    initial.top = -1;
    
    return initial;
}

int top(StackType *S)
{
    // Returns and updates top index;
    S->top = S->size-1;
    return S->top;
}

int isStackFull(StackType S)
{
    return S.size == MAX_SIZE;
}

int isStackEmpty(StackType S)
{
    return S.size == 0;
}

int push(StackType *S, int elem)
{
    int pushed = 0;
    
    if (!isStackFull(*S))
    {
        S->stackVal[S->size] = elem;
        S->size += 1;
        top(S);
        pushed = 1;
    }

    return pushed;
}

int pop(StackType *S)
{
    int popElem = -1;

    if (!isStackEmpty(*S))
    {
        popElem = S->stackVal[S->top];
        S->size -= 1;
        top(S);
    }

    return popElem;
}

void dispStack(StackType S)
{
    int i;

    printf("<Stack>{");
    for (i = 0; i < S.size; i++)
    {
        printf("%d", S.stackVal[i]);
        if (i != S.size-1)
            printf(", ");
    }

    printf("}\n");
}

// int main()
// {

//     StackType S;
//     S = createStack();
//     int test[5] = {1,2,3,4,5};
//     int i;
//     printf("%d", S.size);

//     printf("%d", S.size);

//     for (i = 0; i < 5; i++)
//     {
//         push(&S, test[i]);
//     }
//     dispStack(S);
//     printf("%d", pop(&S));
//     dispStack(S);
//     return 0;
// }

