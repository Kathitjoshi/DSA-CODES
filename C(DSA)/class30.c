//Threaded BST

#include <stdio.h>
#include <stdlib.h>  // Added for malloc

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
    int lthread;  // Indicates if left is a thread (1: thread, 0: child)
    int rthread;  // Indicates if right is a thread (1: thread, 0: child)
} NODE;

NODE* createNode(int data) {
    NODE *nn = (NODE*)malloc(sizeof(NODE));
    nn->data = data;
    nn->lthread = 1;  // By default, threads are present
    nn->rthread = 1;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

NODE* insertNode(NODE *root, int data) {
    NODE *t = root, *parent = NULL, *nn;
    nn = createNode(data);

    if (root == NULL) {  // Tree is empty
        root = nn;
        return root;
    }

    // Find the parent where the new node should be inserted
    while (t != NULL) {
        parent = t;
        if (data < t->data) {
            if (t->lthread == 0)  // Not a thread, move to the left child
                t = t->left;
            else
                break;
        } else if (data > t->data) {
            if (t->rthread == 0)  // Not a thread, move to the right child
                t = t->right;
            else
                break;
        } else {
            printf("Duplicate key\n");
            return root;
        }
    }

    // Insert the node in the appropriate position
    if (data < parent->data) {
        nn->left = parent->left;  // Inorder predecessor
        nn->right = parent;       // Inorder successor
        parent->left = nn;
        parent->lthread = 0;      // Left child exists now
    } else {
        nn->left = parent;        // Inorder predecessor
        nn->right = parent->right;// Inorder successor
        parent->right = nn;
        parent->rthread = 0;      // Right child exists now
    }

    return root;
}

// Inorder traversal for Threaded Binary Search Tree
void inorder(NODE* root) {
    if (root == NULL) {
        printf("Empty Tree\n");
        return;
    }

    // Go to the leftmost node
    NODE *t = root;
    while (t->lthread == 0)
        t = t->left;

    // Traverse the tree using threads
    while (t != NULL) {
        printf("%d ", t->data);

        // Find the inorder successor
        if (t->rthread == 1) {
            t = t->right;
        } else {
            t = t->right;
            while (t != NULL && t->lthread == 0)
                t = t->left;
        }
    }
}

int main() {
    NODE *tbst = NULL;
    int data, ch;

    // Insert nodes into the threaded binary search tree
    do {
        printf("\nEnter the data: ");
        scanf("%d", &data);
        tbst = insertNode(tbst, data);
        printf("\nTo continue press 1: ");
        scanf("%d", &ch);
    } while (ch == 1);

    // Perform inorder traversal
    printf("\nInorder traversal: ");
    inorder(tbst);
    printf("\n");

    return 0;
}
