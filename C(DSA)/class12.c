//Applications of Stack:Infix to postfix expression

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct Stack {
    int top;
    char items[MAX];
};

void push(struct Stack* s, char item) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = item;
}

char pop(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

char peek(struct Stack* s) {
    if (s->top == -1) {
        return -1;
    }
    return s->items[s->top];
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

int isOperand(char ch) {
    return isalnum(ch);
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '$':
            return 3;
        case '^':
            return 4;
    }
    return -1;
}

void infixToPostfix(char* exp) {
    struct Stack s;
    s.top = -1;
    int i, k;

    for (i = 0, k = -1; exp[i]; ++i) 
    {
        if (isOperand(exp[i])) 
        {
            exp[++k] = exp[i];
        } 
        else if (exp[i] == '(')
         {
            push(&s, exp[i]);
        } 
        else if (exp[i] == ')') 
        {
            while (!isEmpty(&s) && peek(&s) != '(') {
                exp[++k] = pop(&s);
            }
            if (!isEmpty(&s) && peek(&s) != '(') {
                printf("Invalid Expression\n");
                return;
            } else {
                pop(&s);
            }
        } 
        else 
        {
            while (!isEmpty(&s) && precedence(exp[i]) <= precedence(peek(&s))) {
                exp[++k] = pop(&s);
            }
            push(&s, exp[i]);
        }
    }

    while (!isEmpty(&s)) {
        exp[++k] = pop(&s);
    }

    exp[++k] = '\0';
    printf("Postfix expression: %s\n", exp);
}

int main() {
    char exp[MAX];
    while(1){
    printf("Enter infix expression: ");
    scanf("%s", exp);
    infixToPostfix(exp);
    }
    return 0;
}
