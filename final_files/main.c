#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stack.c"
#include "queue.c"
#include "evaluate-postfix.c"
#include "infix-to-postfix.c"

typedef char String[256];

int main()
{
    String infix;
    Queue postfix;
    int result;

    do
    {
        scanf("%s", infix);
        scanf("%*c");
        printf("\n");
        if (strcmp(infix, "QUIT") != 0)
        {
            postfix = convertToPostfix(infix);
            evaluatePostfix(postfix);
        }
    } while (strcmp(infix, "QUIT") != 0);
    

    return 0;
}