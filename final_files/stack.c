// This C file contains the implementations and definitions for the operations of a Stack data structure.

#include "stack.h" // Module file for a Stack data structure.

// Operator Stack Operations

/* createStackOperator() creates an empty operator stack and returns it.
   @return the created empty operator stack.
*/
StackOperator
createStackOperator() 
{
    StackOperator stack;

    stack.size = MAX_SIZE_STACK;
    stack.top = -1;
    strcpy(stack.list[0], "\0");
    
    return stack;
}

/* pushOperator() inserts an operator element into the given stack.
   @param stack - the address of the stack where the element will be inserted.
   @param token - the operator element that will be inserted into the stack.
   Pre-condition/s: stack is not full.
*/
void
pushOperator(StackOperator* stack, Operator token) 
{
    stack->top += 1;
    strcpy(stack->list[stack->top], token);
}

/* popOperator() deletes the topmost operator element from the stack and stores it at an address.
   @param stack - the address of the stack where the element will be deleted.
   @param token - the address where the deleted operator element will be stored.
   Pre-condition/s: stack is not empty.
*/
void
popOperator(StackOperator* stack, Operator token) 
{
    strcpy(token, stack->list[stack->top]);
    stack->top -= 1;
}

/* getTopOperator() gets the topmost operator element of the stack and stores it at an address.
   @param stack - the stack to be considered.
   @param token - the address where the topmost operator element will be stored.
*/
void
getTopOperator(StackOperator stack, Operator token) 
{
    strcpy(token, stack.list[stack.top]);
}

/* isStackOperatorEmpty() checks if the given stack is empty or not.
   @param stack - the stack to be considered.
   @return 1 if the stack is empty and 0 if not.
*/
int
isStackOperatorEmpty(StackOperator stack) 
{
    if (stack.top == -1)
        return 1;
    else
        return 0;
}

/* isStackOperatorFull() checks if the given stack is full or not.
   @param stack - the stack to be considered.
   @return 1 if the stack is full and 0 if not.
*/
int
isStackOperatorFull(StackOperator stack) 
{
    if (stack.top + 1 == stack.size)
        return 1;
    else
        return 0;
}

// Operand Stack Operations

/* createStackOperand() creates an empty operand stack and returns it.
   @return the created empty operand stack.
*/
StackOperand
createStackOperand() 
{
    StackOperand stack;

    stack.size = MAX_SIZE_STACK;
    stack.top = -1;
    stack.list[0] = 0;

    return stack;
}

/* pushOperand() inserts an integer element into the given stack.
   @param stack - the address of the stack where the element will be inserted.
   @param token - the integer element that will be inserted into the stack.
   Pre-condition/s: stack is not full.
*/
void
pushOperand(StackOperand* stack, int token) 
{
    stack->top += 1;
    stack->list[stack->top] = token;
}

/* popOperand() deletes the topmost integer element from the stack and returns it.
   @param stack - the address of the stack where the element will be deleted.
   @return the deleted integer element.
   Pre-condition/s: stack is not empty.
*/
int
popOperand(StackOperand* stack) 
{
    int token = stack->list[stack->top];
    stack->top -= 1;

    return token;
}

/* getTopOperand() gets the topmost integer element of the stack and returns it.
   @param stack - the stack to be considered.
   @return the topmost integer element.
*/
int
getTopOperand(StackOperand stack) 
{
    int token = stack.list[stack.top];
    return token;
}

/* isStackOperandEmpty() checks if the given stack is empty or not.
   @param stack - the stack to be considered.
   @return 1 if the stack is empty and 0 if not.
*/
int
isStackOperandEmpty(StackOperand stack) 
{
    if (stack.top == -1)
        return 1;
    else
        return 0;
}

/* isStackOperatorFull() checks if the given stack is full or not.
   @param stack - the stack to be considered.
   @return 1 if the stack is full and 0 if not.
*/
int
isStackOperandFull(StackOperand stack) 
{
    if (stack.top + 1 == stack.size)
        return 1;
    else
        return 0;
}