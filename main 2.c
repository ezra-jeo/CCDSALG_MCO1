typedef char String[256];

#include "stdio.h"
#include "ctype.h"
#include "stack.c"
#include "queue.c"
#include "infix-to-postfix.c"

int
main () {
    Queue  postfix;
    String infix = "100*20+33000*4/500+6+7-8*9";
    postfix = convertToPostfix(infix);

    return 0;
}