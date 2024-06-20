// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// #include "stack 2.c"
// #include "queue 2.c"

typedef char String[256];

/*  isNum determines whether a character element represents an integer.
    @param elem, character element to determine if is an integer;
    @return 1 if true, 0 if false
*/
int isNum(char elem)
{
    int isNum = 0;

    if (elem >= '0' && elem <= '9')
    {
        isNum = 1;
    }

    return isNum;
}


/*  evaluate evaluates the expression given two operands and an operator.
    @param operand1, first integer operand
    @param operand2, second integer operand
    @param op, operator as a string
    @return result of the evaluation
*/
int evaluate(int operand1, int operand2, Operator op)
{   
    int result = 0;

    if (strcmp(op, "^") == 0)
        result = (int) pow(operand1, operand2);
    else if (strcmp(op, "*") == 0)
        result = operand1 * operand2;
    else if (strcmp(op, "/") == 0)    
        result = operand1 / operand2; 
    else if (strcmp(op, "%") == 0)
        result = operand1 % operand2;
    else if (strcmp(op, "+") == 0)
        result = operand1 + operand2;
    else if (strcmp(op, "-") == 0)
        result = operand1 - operand2;
    else if (strcmp(op, "&&") == 0)
        result = operand1 && operand2;
    else if (strcmp(op, "||") == 0)
        result = operand1 || operand2;
    else if (strcmp(op, ">") == 0)
        result = operand1 > operand2;
    else if (strcmp(op, ">=") == 0)
        result = operand1 >= operand2;
    else if (strcmp(op, "<") == 0)
        result = operand1 < operand2;
    else if (strcmp(op, "<=") == 0)
        result = operand1 <= operand2;
    else if (strcmp(op, "!=") == 0)
        result = operand1 != operand2;
    else if (strcmp(op, "==") == 0)
        result = operand1 == operand2;
    // do ! pa
    return result;
}

/*  evaluateUnary evaluates a unary expresion.
    @param operand1, first integer operand
    @param op, unary operator as a string
    @return result of the evaluation
*/
int evaluateUnary(int operand1, Operator op)
{
    int result = 0;

    if (strcmp(op, "!") == 0)
        result = !operand1;

    return result;
}

/*  evaluatePostfix evaluates a given postfix expression.
    @param queue, resulting queue of the postfix conversion
    @param *result, pointer to the variable which holds the result of the evaluation
    @return None
*/
void evaluatePostfix(Queue queue, int *result)
{
    // Variables
    int isEmpty = 0;
    int operatorCtr = 0;
    int operandCtr = 0;
    int operand1 = 0;
    int operand2 = 0;
    int divisionByZero = 0; // Division by zero flag
    char buffer; // Buffer for dequeued elements
    String operand = ""; // String to use to convert multidigit nums to integers.
    Operator operator; // String to use to convert operators to string equivalents.
    StackOperand operands = createStackOperand();

    // Following the algorithm for evaluation

    while (!isEmpty && !divisionByZero)
    {
        // Dequeue the queue
        buffer = dequeue(&queue);
        strcpy(operator, " ");
        operatorCtr = 0;
        strcpy(operand, " ");
        operandCtr = 0;
        // resetting converters and corresponding counters
        
        if (isNum(buffer)) // If the value is an operand
        {
            // Getting the operand
            while(buffer != ' ' && !isEmpty)
            {   
                operand[operandCtr++] = buffer;
                if (!queueEmpty(queue))
                    buffer = dequeue(&queue);
                else
                    isEmpty = 1;
            }
            
            // Push to the stack
            pushOperand(&operands, atoi(operand)); // converts string to corresponding integer.

            //Tracker for debugging.
            // stackOperandDisplay(operands);
            // printf("\n");

        }
        else
        {
            // Getting the operator
            while(buffer != ' ' && !isEmpty)
            {
                operator[operatorCtr++] = buffer;
                operator[operatorCtr] = '\0';

                if (!queueEmpty(queue))
                    buffer = dequeue(&queue);
                else
                    isEmpty = 1;
            }

            // Evaluation
            if (strcmp(operator, "!") != 0) // If not a unary ex[ressopm]
            {
                // Popping operands
                operand2 = popOperand(&operands);
                operand1 = popOperand(&operands);

                if (operand2 == 0 && strcmp(operator, "/") == 0) // If a zero division case
                {
                    divisionByZero = 1;
                    printf("Division by zero error!\n");
                }
                else
                {
                    pushOperand(&operands, evaluate(operand1, operand2, operator)); // Push the resulting value back to the stack           

                    //Tracker for debugging.
                    // printf("\nPop 1: %d, Pop 2: %d, operator %s\n", operand1, operand2, operator);
                    // printf("%d\n", evaluate(operand1, operand2, operator));
                    // stackOperandDisplay(operands);
                    // printf("\n");

                }
            }
            else // if unary expression
            {
                // Popping operand
                operand1 = popOperand(&operands);
                pushOperand(&operands, evaluateUnary(operand1, operator)); // Push the resulting value back to the stack

                //Tracker for debugging.
                // printf("\nPop 1: %d, operator %s\n", operand1, operator);
                // printf("%d\n", evaluateUnary(operand1, operator));
                // stackOperandDisplay(operands);
                // printf("\n");

            }


        }
    }

    if (!divisionByZero) // If a valid result
        *result = popOperand(&operands); // Store the result
}

// int main()
// {
//     int i;
//     Queue postfix = createQueue();
//     Operator op = "+";
//     char infix[255] = "10 3 %";
//     for (i = 0; i < 6; i++)
//     {
//         enqueue(&postfix, infix[i]);
//     }
//     //queueDisplay(postfix);
//     int result = 0;
//     evaluatePostfix(postfix, &result);
//     printf("\nResult: %d\n", result);
//     // printf("%d %d\n", evaluate(4, 2, "+"), 4 + 2);

//     return 0;
// }