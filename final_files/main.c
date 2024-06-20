typedef char String[256];

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stack.c"
#include "queue.c"
#include "evaluate-postfix.c"
#include "infix-to-postfix.c"


int main()
{
    String infix;
    Queue postfix;

    do
    {
        scanf("%s", infix);
        scanf("%*c");
        if (strcmp(infix, "QUIT") != 0)
        {
            postfix = convertToPostfix(infix);
            evaluatePostfix(postfix);
            printf("\n");
        }
    } while (strcmp(infix, "QUIT") != 0);
    

    return 0;
}