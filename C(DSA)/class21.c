//BST Traversals using the iteration method
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* next; // used for stack
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = newNode->next = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
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

// Function for iterative inorder traversal
void inorderTraversal(struct Node* root) {
    struct Node* stack = NULL;
    struct Node* current = root;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }
        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
}

// Function for iterative preorder traversal
void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* stack = NULL;
    push(&stack, root);

    while (!isEmpty(stack)) {
        struct Node* current = pop(&stack);
        printf("%d ", current->data);

        if (current->right) {
            push(&stack, current->right);
        }
        if (current->left) {
            push(&stack, current->left);
        }
    }
}

// Function for iterative postorder traversal
void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* stack1 = NULL;//to store nodes temporarily
    struct Node* stack2 = NULL;//to store postorder traversal sequence
    push(&stack1, root);

    while (!isEmpty(stack1)) {
        struct Node* current = pop(&stack1);
        push(&stack2, current);

        if (current->left) {
            push(&stack1, current->left);
        }
        if (current->right) {
            push(&stack1, current->right);
        }
    }

    while (!isEmpty(stack2)) {
        struct Node* current = pop(&stack2);
        printf("%d ", current->data);
    }
}

int main() {
    // Main function to test the traversals
    struct Node* root = insertNode(NULL, 1);
    insertNode(root, 2);
    insertNode(root, 4);
    insertNode(root, 3);
    insertNode(root, 5);
    insertNode(root, 6);
    insertNode(root, 7);
    insertNode(root, 8);
    insertNode(root, 9);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
