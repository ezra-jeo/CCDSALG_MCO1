#include <stdio.h>
#include "Stack.c"
#include "StackChar.c"
#include "Queue.c"

typedef char String255[256];

int isNum(char elem)
{
    int isNum = 0;

    if (elem >= '0' && elem <= '9')
    {
        isNum = 1;
    }

    return isNum;
}

void pushElem(StackType *S, StackCharType *SC, String255 infix, int size)
{
    int intBuffer;
    int intBuffer2;
    int i;
    char charBuffer;

    for (i = 0; i < size; i++)
    {
        if (isNum(infix[i]))
        {
            intBuffer = infix[i] - '0';

            if (i > 0 && isNum(infix[i-1]))
            {
                intBuffer2 = pop(S);
                intBuffer2 *= 10;
                intBuffer2 += intBuffer;

                push(S, intBuffer2);
            }    
            else
            {
                push(S, intBuffer);
            }
        }
        else
        {
            charBuffer = infix[i];
            pushChar(SC, charBuffer);
        }
    }
    
}

int takePrecedence(char operator)
{
    
}

void convertToPostfix(StackType *S, StackCharType *SC, QueueType *postfix, int size, int sizeChar)
{


}

int main()
{
    printf("%d\n", isNum('+'));
    String255 infix = "1+2/34*4";
    StackType S = createStack();
    StackCharType SC = createCharStack();
    int intBuffer = infix[2] - '0';

    printf("%d\n", isStackFull(S));
    printf("%d\n", intBuffer);
    pushElem(&S, &SC, infix, 8);
    printf("%d %d\n", isStackEmpty(S), isStackCharEmpty(SC));
    dispStack(S);
    dispCharStack(SC);
    return 0;
}