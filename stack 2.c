// This C file contains the implementations and definitions for the operations of a Stack data structure.

#include "string.h"
#include "stack.h"

// Operator Stack Operations

StackOperator
createStackOperator () 
{
    StackOperator stack;

    stack.size = MAX_SIZE_STACK;
    stack.top = -1;
    strcpy(stack.list[0], "\0");
    
    return stack;
}

void
pushOperator (StackOperator* stack, Operator token) 
{
    stack->top += 1;
    strcpy(stack->list[stack->top], token);
}

void
popOperator (StackOperator* stack, Operator token) 
{
    strcpy(token, stack->list[stack->top]);
    stack->top -= 1;
}

void
topOperator (StackOperator stack, Operator token) 
{
    strcpy(token, stack.list[stack.top]);
}

int
stackOperatorEmpty (StackOperator stack) 
{
    if (stack.top == -1)
        return 1;
    else
        return 0;
}

int
stackOperatorFull (StackOperator stack) 
{
    if (stack.top + 1 == stack.size)
        return 1;
    else
        return 0;
}

// Operand Stack Operations

StackOperand
createStackOperand () 
{
    StackOperand stack;

    stack.size = MAX_SIZE_STACK;
    stack.top = -1;
    stack.list[0] = 0;

    return stack;
}

void
pushOperand (StackOperand* stack, int token) 
{
    stack->top += 1;
    stack->list[stack->top] = token;
}

int
popOperand (StackOperand* stack) 
{
    int token = stack->list[stack->top];
    stack->top -= 1;

    return token;
}

int
topOperand (StackOperand stack) 
{
    int token = stack.list[stack.top];
    return token;
}

int
stackOperandEmpty (StackOperand stack) 
{
    if (stack.top == -1)
        return 1;
    else
        return 0;
}

int
stackOperandFull (StackOperand stack) 
{
    if (stack.top + 1 == stack.size)
        return 1;
    else
        return 0;
}