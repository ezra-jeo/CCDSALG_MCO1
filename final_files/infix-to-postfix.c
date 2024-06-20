// This C file contains the implementations for converting infix to postfix expressions.

/* enqueueOperator() stores the given operator into the postfix queue.
   @param operator - the operator to be stored into the postfix queue.
   @param postfix - the address of the postfix queue where the operator will be stored.
*/
void
enqueueOperator(Operator operator, Queue* postfix)
{
    int k = 0;

    while (k < strlen(operator)) 
    {
        if (!isQueueFull(*postfix)) 
            enqueue(postfix, operator[k]);
        k++;
    }
}

/* hasLeftAssociative() checks if the given operator is left-associative or not.
   @param operator - the operator to be considered.
   @return 1 if the operator is left-associative and -1 if not.
*/
int 
hasLeftAssociative(Operator operator)
{
    if (strcmp(operator, "!") == 0 || strcmp(operator, "^") == 0)
        return -1;
    else
        return 1;
}

/* hasHigherPriority() checks if the operator in the infix has higher priority than the top operator in the stack.
   @param operatorInfix - the operator from the infix.
   @param operatorStack - the operator from the stack.
   @return 1 if the operator in the infix has higher priority than the operator in the stack and -1 if otherwise.
*/
int
hasHigherPriority(Operator operatorInfix, Operator operatorStack) 
{
    // This variable consists of the priority table of the operators.
    Operator priorityTable[9][4] = {{"!"},
                                    {"^"},
                                    {"*", "/", "%"}, 
                                    {"+", "-"}, 
                                    {"<", ">", "<=", ">="}, 
                                    {"==", "!="}, 
                                    {"&&"}, 
                                    {"||"},
                                    {"("}}; // "(" is placed the farthest since it is not considered for the conversion to postfix.
    int      i = 0, j = 0;
    int      indexInfix = -1, indexStack = -1;

    // This group of codes loops through the table to get the priority value of the given operators, based on their indexes.
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

    // This group of codes checks whether the operator in the infix has higher priority than the operator in the stack or not.
    if (indexInfix < indexStack)
        return 1;
    else
        return -1;
}

/* displayPostfix() displays the postfix expression.
   @param postfix - the queue that stores the postfix expression.
*/
void
displayPostfix(Queue postfix) 
{
    while (!isQueueEmpty(postfix))
        printf("%c", dequeue(&postfix));

    printf("\n");
}

/* convertToPostfix() converts the given infix to postfix expression and returns it.
   @param infix - the string infix expression to be converted to postfix expression.
   @return the postfix expression queue.
   Pre-condition/s: infix does not have any spaces between tokens.
*/
Queue
convertToPostfix(String infix) 
{
    StackOperator stack = createStackOperator(); // The stack where the operators will be stored.
    Operator      operatorInfix;
    Operator      operatorStack;
    Queue         postfix = createQueue(); // The queue where the postfix expression will be stored.
    int           size = strlen(infix);
    int           i = 0;

    // This group of codes loops through the entire infix expression and stores the tokens into the postfix queue accordingly and properly.
    while (i < size) 
    {
        // This group of codes checks whether the token is a digit or not.
        if (isdigit(infix[i])) 
        {
            // This group of codes loops through the expression and stores the token into the postfix queue directly until the token is not a digit.
            do
            {
                if (!isQueueFull(postfix))
                    enqueue(&postfix, infix[i]);
                i++;            
            } while (isdigit(infix[i]));

            if (!isQueueFull(postfix))
                enqueue(&postfix, ' '); // This line of code puts a space into the postfix queue after every complete integer token as a marker.
        }
        else 
        {
            // This group of codes checks whether the operator token is composed of two or one character/s and stores them into a string.
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

            // This group of codes checks whether the operator token is a parenthesis or not.
            if (strcmp(operatorInfix, "(") == 0) 
                pushOperator(&stack, operatorInfix); // This line of code pushes the "(" token into the stack.
            else if (strcmp(operatorInfix, ")") == 0)
            {
                // This group of codes pops the operator tokens from the stack and stores them into the postfix queue until it is the "(" token.
                do
                {
                    popOperator(&stack, operatorStack);

                    if (strcmp(operatorStack, "(") != 0)
                    {
                        enqueueOperator(operatorStack, &postfix);

                        if (!isQueueFull(postfix))
                            enqueue(&postfix, ' '); // This line of code puts a space into the postfix queue after every complete operator token as a marker.
                    }
                } while (strcmp(operatorStack, "(") != 0);
            }
            else 
            {
                // This group of codes checks whether the stack is empty or not.
                if (isStackOperatorEmpty(stack))
                    pushOperator(&stack, operatorInfix); // This line of code pushes the operator token directly into the stack.
                else 
                {
                    // This group of codes loops and checks the operator token in the stack and in the infix expression and pushes/pops operator tokens from the stack based on their priority and associativity.
                    do
                    {
                        getTopOperator(stack, operatorStack);

                        // This group of codes pops the operator token in the stack and stores it into the postfix queue when it has higher priority and left associativity.
                        if (hasHigherPriority(operatorInfix, operatorStack) != 1 && hasLeftAssociative(operatorInfix) == 1) 
                        {
                            popOperator(&stack, operatorStack);
                            enqueueOperator(operatorStack, &postfix);

                            if (!isQueueFull(postfix))
                                enqueue(&postfix, ' '); // This line of code puts a space into the postfix queue after every complete operator token as a marker.
                        }
                        else 
                        {
                            if (!isStackOperatorFull(stack))
                                pushOperator(&stack, operatorInfix); // This line of code pushes the operator token into the stack, otherwise.
                        }
                    } while (!isStackOperatorEmpty(stack) && hasHigherPriority(operatorInfix, operatorStack) != 1 && hasLeftAssociative(operatorInfix) == 1);

                    // This group of codes pushes the operator token into stack when the stack is already empty.
                    if (isStackOperatorEmpty(stack))
                        pushOperator(&stack, operatorInfix);
                }
            }
        }
    }

    // This group of codes empties the stack and stores the operator tokens into the postfix queue.
    while (!isStackOperatorEmpty(stack)) 
    {
        popOperator(&stack, operatorStack);
        enqueueOperator(operatorStack, &postfix);

        if (!isQueueFull(postfix) && !isStackOperatorEmpty(stack))
            enqueue(&postfix, ' '); // This line of code puts a space into the postfix queue after every complete operator token as a marker, as long as it is not the last token.
    }

    displayPostfix(postfix);
    return postfix;
}
