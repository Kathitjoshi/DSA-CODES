//BST implementation in C by LL



#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function prototype for findMinNode
Node* findMinNode(Node* root);


Node* delNode(Node* r, int ele) {
    Node* temp;
    if (r == NULL)
    {
        printf("Element not found\n");
        return r;

    }

    if (ele < r->data)
        r->left = delNode(r->left, ele);
    else if (ele > r->data)
        r->right = delNode(r->right, ele);
    else {
        if (r->left == NULL && r->right == NULL) { // Node to be deleted is a leaf node
            free(r);
            return NULL;
        } else if (r->left == NULL) { // 1 right child or No children
            temp = r->right;
            free(r);
            return temp;
        } else if (r->right == NULL) { // 1 left child or No children
            temp = r->left;
            free(r);
            return temp;
        } else { // Node to be deleted has both children
            // Finding the minimum value node in the right subtree (inorder successor)
            temp = findMinNode(r->right);
            r->data = temp->data;
            r->right = delNode(r->right, temp->data);
        }
    }
    
    return r;
}
  
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* search(Node* root, int data) {
    //iterative search

    // int flag=0;
    // if(root==NULL)
    // {
    //     printf("Tree is empty!!");
    //     return NULL;
    // }
    // while(root!=NULL)
    // {
    //     if(root->data == data)
    //     {
    //         printf("data is found!!");
    //         return root;
    //     }    
    //     else if(root->data < data)
    //         root = root->right;
    //     else
    //         root = root->left;
    // }
    // if(flag==0)
    // {
    //     printf("Data not found!!");
    // }

    //or(recursive search)

     if (root == NULL || root->data == data) {
        if (root == NULL) {
            printf("Data not found!!\n");
        } else {
            printf("Data is found!!\n");
        }
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }

}

Node* insertNode(Node* root, int data) {
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

void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

Node* findMinNode(Node* root) {
    Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* findMaxNode(Node* root) {
    Node* current = root;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current;
}

int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeafNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int findHeight(Node* root) {
    if (root == NULL) {
        return -1; // Return -1 for height of empty tree
    }
    if(root->left == NULL && root->right == NULL) {
        return 0;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    int nodeCount = countNodes(root);
    printf("Number of nodes: %d\n", nodeCount);

    int leafNodeCount = countLeafNodes(root);
    printf("Number of leaf nodes: %d\n", leafNodeCount);

    Node* minNode = findMinNode(root);
    if (minNode != NULL) {
        printf("Minimum node: %d\n", minNode->data);
    }

    Node* maxNode = findMaxNode(root);
    if (maxNode != NULL) {
        printf("Maximum node: %d\n", maxNode->data);
    }

    int height = findHeight(root);
    printf("Height of the tree: %d\n", height);

    int key;
    Node* searchNode = search(root, 90);
    while(1)
    {

    
    root = delNode(root, 30);
    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
    }

}
