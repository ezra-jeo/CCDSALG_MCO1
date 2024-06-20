// This C file contains the implementations and definitions for evaluating postfix expressions.

/* isNum() determines whether a character element represents an integer.
   @param elem - the character element to determine if is an integer.
   @return 1 if true and 0 if false.
*/
int 
isNum(char elem)
{
    int isNum = 0; // Flag if the character is a number.

    if (elem >= '0' && elem <= '9') // Determines if character belongs in the range from 0 to 9 in the ascii table.
    {
        isNum = 1; // Flag
    }

    return isNum; 
}

/* power() raises a number by another number as exponent.
   @param a - the base integer.
   @param b - the exponent.
   @return the result of the exponentiation.
*/
int 
power(int a, int b)
{
    int i; 
    int result = 1; // Variable to hold the result of the exponentiation.

    for (i = 0; i < b; i++)
    {
        result *= a; // Product loop
    }

    return result;
}

/* toNum() converts the string representation of number to the integer equivalent.
   @param number - a number in string form.
   @return the number in integer form.
*/
int 
toNum(String number)
{
    int i;
    int result = 0;

    for (i = 0; number[i] != '\0'; i++)
    {
        result = result * 10 + number[i] - '0'; // Multiplies by ten to accommodate for multidigt numbers.
        // number[i] - '0' gets its distance from character 0, which is the number itself.
    }
    
    return result;
}

/* evaluate() evaluates the expression given two operands and an operator.
   @param operand1 - the first integer operand.
   @param operand2 - the second integer operand.
   @param op - the operator as a string.
   @return the result of the evaluation.
*/
int 
evaluate(int operand1, int operand2, Operator op)
{   
    int result = 0; // Variable to hold the result

    // Checking of the operator and evaluating the operation
    if (strcmp(op, "^") == 0)
        result = power(operand1, operand2);
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

    return result;
}

/* evaluateUnary() evaluates a unary expresion.
   @param operand - the integer operand.
   @param op - the unary operator as a string.
   @return the result of the evaluation.
*/
int 
evaluateUnary(int operand, Operator op)
{
    int result = 0; // Variable to hold the result

    // Checking if logical not and evaluating the operation
    if (strcmp(op, "!") == 0)
        result = !operand;

    return result;
}

/* evaluatePostfix() evaluates a given postfix expression.
   @param queue - the resulting queue of the postfix conversion.
*/
void 
evaluatePostfix(Queue queue)
{
    // Variables
    int isEmpty = 0;        // Flag if empty
    int operatorCtr = 0;    // Counter for when obtaining string representation of operator
    int operandCtr = 0;     // Counter for when obtaining string representation of operand
    int operand1 = 0;       // First operand
    int operand2 = 0;       // Second operand
    int divisionByZero = 0; // Division by zero flag
    char buffer;            // Buffer for dequeued elements
    String operand = "";    // String to use to convert multidigit nums to integers.
    Operator operator;      // String to use to convert operators to string equivalents.
    StackOperand operands;  // stack for the operands
    
    operands = createStackOperand(); // Initialization

    while (!isEmpty && !divisionByZero)
    {
        // Dequeue the queue
        
        // resetting converters and corresponding counters
        buffer = dequeue(&queue);
        strcpy(operator, " ");
        operatorCtr = 0;
        strcpy(operand, " ");
        operandCtr = 0;
        
        if (isNum(buffer)) // If the value is an operand
        {
            // Get the operand as a string
            while(buffer != ' ' && !isEmpty)
            {   
                operand[operandCtr++] = buffer;
                if (!isQueueEmpty(queue))
                    buffer = dequeue(&queue);
                else
                    isEmpty = 1;
            }
            
            // Push to the stack
            pushOperand(&operands, toNum(operand)); // converts string to corresponding integer.
        }
        else // If not an integer, then an operator
        {
            // Get the operator as a string
            while(buffer != ' ' && !isEmpty)
            {
                operator[operatorCtr++] = buffer;
                operator[operatorCtr] = '\0';

                if (!isQueueEmpty(queue))
                    buffer = dequeue(&queue);
                else
                    isEmpty = 1;
            }

            // Evaluation
            if (strcmp(operator, "!") != 0) // If not a unary expression
            {
                // Pop operands needed for operation
                operand2 = popOperand(&operands);
                operand1 = popOperand(&operands);

                if (operand2 == 0 && (strcmp(operator, "/") == 0 || strcmp(operator, "%") == 0)) // If a zero division case
                {
                    divisionByZero = 1; // Flag, which also terminates the while loop
                    printf("Division by zero error!\n"); // Error message
                }
                else
                {
                    // Push the resulting value back to the stack           
                    pushOperand(&operands, evaluate(operand1, operand2, operator));
                }
            }
            else // if unary expression
            {
                // Pop operand for unary expression
                operand1 = popOperand(&operands);
                pushOperand(&operands, evaluateUnary(operand1, operator)); // Push the resulting value back to the stack
            }
        }
    }

    if (!divisionByZero) // If a valid result
        printf("%d\n",popOperand(&operands)); // Print the result
}
