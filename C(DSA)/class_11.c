//Applications of Stack:Evaluating postfix expression 
//3rd way of doing stacks: defining array of list items and top(here res) of the stack w/o structure and individually.


#include <stdio.h>
#include <math.h>

int isnum(int c) {
    if (c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

void push(int* stk, int* top, int ele) {
    stk[++(*top)] = ele;
}

int pop(int* stk, int* top) {
    return stk[(*top)--];
}

int eval(int op1, int op2, char ch) {
    switch (ch) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '$': return pow(op1, op2); // Fixed the power operator
    }
}

int postfix_eval(char* postfix) {
    int opndstk[20], top = -1, op1, op2, res;
    int i = 0;

    char ch;
    while (postfix[i] != '\0') {
        ch = postfix[i];
        if (isnum(ch))
            push(opndstk, &top, ch - '0'); // Fixed the conversion from char to int
        else {
            op2 = pop(opndstk, &top);
            op1 = pop(opndstk, &top);
            res = eval(op1, op2, ch);
            push(opndstk, &top, res);
        }
        i++;
    }
    return opndstk[top];
}

int main() {
    int res;
    char postfix[10];
    while(1){
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    res = postfix_eval(postfix);
    printf("Value of postfix expression: %d\n", res);
    }
    return 0;
}