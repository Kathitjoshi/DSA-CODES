//Expression binary tree creation and evaluation(postfix)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char value;
    struct Node* left;
    struct Node* right;
    struct Node* next; // used for stack
};

struct Node* newNode(char value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->left = node->right = node->next = NULL;
    return node;
}

// Function to push a node onto the stack
void push(struct Node** top, struct Node* node) {
    node->next = *top;
    *top = node;
}

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Function to pop a node from the stack
struct Node* pop(struct Node** top) {
    if (isEmpty(*top)) {
        return NULL;
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    temp->next = NULL;
    return temp;
}

struct Node* constructTree(char postfix[]) {
    struct Node* stack = NULL;
    for (int i = 0; postfix[i]; i++) {
        struct Node* t = newNode(postfix[i]);
        if (isalnum(postfix[i])) {
            push(&stack, t);
        } else {
            t->right = pop(&stack);
            t->left = pop(&stack);
            push(&stack, t);
        }
    }
    return pop(&stack);
}

int evaluate(struct Node* root) {
    if (!root->left && !root->right) return root->value - '0';
    int left_val = evaluate(root->left);
    int right_val = evaluate(root->right);
    switch (root->value) {
        case '+': return left_val + right_val;
        case '-': return left_val - right_val;
        case '*': return left_val * right_val;
        case '/': return left_val / right_val;
    }
    return 0;
}

int main() {
    char postfix[] = "841*+";
    struct Node* root = constructTree(postfix);
    printf("Result of expression evaluation: %d\n", evaluate(root));
    return 0;
}
