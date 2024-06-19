// This module file contains the declarations for the attributes of a Stack data structure.

#define MAX_SIZE_STACK 255

typedef char Operator[3];

struct stackOperatorTag 
{
    int      size;
    int      top;
    Operator list[MAX_SIZE_STACK];
};

typedef struct stackOperatorTag StackOperator;

struct stackOperandTag 
{
    int size;
    int top;
    int list[MAX_SIZE_STACK];
};

typedef struct stackOperandTag StackOperand;
