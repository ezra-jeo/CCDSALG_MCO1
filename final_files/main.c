#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "stack.c"
#include "queue.c"
#include "evaluate-postfix.c"

int main()
{
    String255 infix;
    Queue postfix;
    int result;

    do
    {
        scanf("%s", infix);
        scanf("%*c");
        //infix-postfix
        // displayQueue
        printf("\n");
        if (strcmp(infix, "QUIT") != 0)
        {
            evaluatePostfix(postfix, &result);
            printf("%d\n", result);
            printf("\n");
        }
    } while (strcmp(infix, "QUIT") != 0);
    

    return 0;
}