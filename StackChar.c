#include <stdio.h>
#define MAX_SIZE 255

struct StackCharTag {
    int size;
    char stackVal[MAX_SIZE];
    int top;
};

typedef struct StackCharTag StackCharType;

StackCharType createCharStack()
{
    StackCharType initial;
    initial.size = 0;
    initial.stackVal[0] = '\0';
    initial.top = -1;

    return initial;
}
int topChar(StackCharType *S)
{
    // Returns and updates top index;
    S->top = S->size-1;
    return S->top;
}

int isStackCharFull(StackCharType S)
{
    return S.size == MAX_SIZE;
}

int isStackCharEmpty(StackCharType S)
{
    return S.size == 0;
}

int pushChar(StackCharType *S, char elem)
{
    int pushed = 0;
    
    if (!isStackCharFull(*S))
    {
        S->stackVal[S->size] = elem;
        S->size += 1;
        topChar(S);
        pushed = 1;
    }

    return pushed;
}

int popChar(StackCharType *S)
{
    char popElem = '\0';

    if (!isStackCharEmpty(*S))
    {
        popElem = S->stackVal[S->size];
        S->size -= 1;
        topChar(S);
    }

    return popElem;
}

void dispCharStack(StackCharType S)
{
    int i;

    printf("<Stack>{");
    for (i = 0; i < S.size; i++)
    {
        printf("%c", S.stackVal[i]);
        if (i != S.size-1)
            printf(", ");
    }

    printf("}\n");
}

// int main()
// {

//     StackCharType S;
//     S = createStack();
//     char test[2] = {'+', '+'};
//     int i;
//     for (i = 0; i < 2; i++)
//     {
//         push(&S, test[i]);
//     }
//     dispStack(S);
//     pop(&S);
//     dispStack(S);
//     printf("%d\n", top(&S));
//     return 0;
// }

