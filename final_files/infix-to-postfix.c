// This C file contains the implementations and definitions for converting infix to postfix expressions.

//#include "stack.c"
//#include "queue.c"
//typedef char String[256];

int 
hasLeftAssociative (Operator operator)
{
    if (strcmp(operator, "!") == 0 || strcmp(operator, "^") == 0)
        return -1;
    else
        return 1;
}
int
hasHigherPriority (Operator operatorInfix, Operator operatorStack) 
{
    Operator priorityTable[9][4] = {{"!"},
                                    {"^"},
                                    {"*", "/", "%"}, 
                                    {"+", "-"}, 
                                    {"<", ">", "<=", ">="}, 
                                    {"==", "!="}, 
                                    {"&&"}, 
                                    {"||"},
                                    {"("}};
    int      i = 0, j = 0;
    int      indexInfix = -1, indexStack = -1;;

    while (i < 9 && (indexInfix == -1 || indexStack == -1)) {
        j = 0;
        while (j < 4 && (indexInfix == -1 || indexStack == -1)) {
            if (strcmp(operatorInfix, priorityTable[i][j]) == 0)
                indexInfix = i;

            if (strcmp(operatorStack, priorityTable[i][j]) == 0)
                indexStack = i;
            
            j++;
        }
        i++;
    }

    if (indexInfix < indexStack)
        return 1;
    else
        return -1;
}

void
displayPostfix (Queue postfix) 
{
    while (!queueEmpty(postfix))
        printf("%c", dequeue(&postfix));

    printf("\n\n");
}

void
displayStack (StackOperator stack)
{
    int i = 0;

    while (i <= stack.top) {
        printf("%s ", stack.list[i]);
        i++;
    }
    
    printf("\n");
}

Queue
convertToPostfix (String infix) 
{
    StackOperator stack = createStackOperator();
    Operator      operatorInfix;
    Operator      operatorStack;
    Queue         postfix = createQueue();
    int           size = strlen(infix);
    int           i = 0;
    int           k = 0;
    char          temp;

    while (i < size) 
    {
        if (isdigit(infix[i])) 
        {
            do
            {
                if (!queueFull(postfix))
                    enqueue(&postfix, infix[i]);
                i++;            
            } while (isdigit(infix[i]));

            if (!queueFull(postfix))
                enqueue(&postfix, ' ');

            printf("Stack: ");
            displayStack(stack);
            printf("Postfix: ");
            displayPostfix(postfix);
        }
        else 
        {
            if (((infix[i] == '<' || infix[i] == '>' || infix[i] == '!' || infix[i] == '=') && infix[i+1] == '=') ||
                (infix[i] == '&' && infix[i+1] == '&') || (infix[i] == '|' && infix[i+1] == '|')) 
            {
                operatorInfix[0] = infix[i];
                i++;
                operatorInfix[1] = infix[i];
                i++;
                operatorInfix[2] = '\0';
            }
            else
            {
                operatorInfix[0] = infix[i];
                i++;
                operatorInfix[1] = '\0';
            }

            if (strcmp(operatorInfix, "(") == 0) 
            {
                pushOperator(&stack, operatorInfix);
                printf("Stack: ");
                displayStack(stack);
                printf("Postfix: ");
                displayPostfix(postfix);
            }
            else if (strcmp(operatorInfix, ")") == 0)
            {
                do
                {
                    topOperator(stack, operatorStack);
                    popOperator(&stack, operatorStack);

                    if (strcmp(operatorStack, "(") != 0)
                    {
                        k = 0;
                        while (k < strlen(operatorStack)) 
                        {
                            if (!queueFull(postfix)) 
                                enqueue(&postfix, operatorStack[k]);
                                k++;
                        }
                        if (!queueFull(postfix))
                            enqueue(&postfix, ' ');

                        printf("Stack: ");
                        displayStack(stack);
                        printf("Postfix: ");
                        displayPostfix(postfix);
                    }
                } while (strcmp(operatorStack, "(") != 0);
            }
            else 
            {
                if (stackOperatorEmpty(stack)) {
                    pushOperator(&stack, operatorInfix);

                    printf("Stack: ");
                    displayStack(stack);
                    printf("Postfix: ");
                    displayPostfix(postfix);
                }
                else 
                {
                    do
                    {
                        topOperator(stack, operatorStack);

                        if (hasHigherPriority(operatorInfix, operatorStack) != 1 && hasLeftAssociative(operatorInfix) == 1) 
                        {
                            if (!stackOperatorEmpty(stack))
                                popOperator(&stack, operatorStack);

                            k = 0;
                            while (k < strlen(operatorStack)) 
                            {
                                if (!queueFull(postfix)) 
                                    enqueue(&postfix, operatorStack[k]);
                                k++;
                            }
                            if (!queueFull(postfix))
                                enqueue(&postfix, ' ');
                        }
                        else 
                        {
                            if (!stackOperatorFull(stack))
                                pushOperator(&stack, operatorInfix);
                        }

                        printf("Stack: ");
                        displayStack(stack);
                        printf("Postfix: ");
                        displayPostfix(postfix);
                    } while (!stackOperatorEmpty(stack) && hasHigherPriority(operatorInfix, operatorStack) != 1 && hasLeftAssociative(operatorInfix) == 1);

                    if (stackOperatorEmpty(stack))
                    {
                        if (!stackOperatorFull(stack))
                            pushOperator(&stack, operatorInfix);

                        printf("Stack: ");
                        displayStack(stack);
                        printf("Postfix: ");
                        displayPostfix(postfix);
                    }
                }
            }
        }
    }

    while (!stackOperatorEmpty(stack)) 
    {
        popOperator(&stack, operatorStack);
        k = 0;
        while (k < strlen(operatorStack)) 
        {
            if (!queueFull(postfix))
                enqueue(&postfix, operatorStack[k]);
            k++;
        }

        if (!queueFull(postfix) && !stackOperatorEmpty(stack))
            enqueue(&postfix, ' ');

        printf("Stack: ");
        displayStack(stack);
        printf("Postfix: ");
        displayPostfix(postfix);
    }

    displayPostfix(postfix);

    return postfix;
}
