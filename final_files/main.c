#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.c"
#include "queue.c"
#include "evaluate-postfix.c"
#include "infix-to-postfix.c"

int main()
{
    String infix;
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
            postfix = convertToPostfix(infix);
            evaluatePostfix(postfix, &result);
            printf("%d\n", result);
            printf("\n");
        }
    } while (strcmp(infix, "QUIT") != 0);
    

    return 0;
}