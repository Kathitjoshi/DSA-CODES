//BST implementation by array

#include<stdio.h>
#define tree_size 7

int tree[tree_size];

void insert(int ele){
    int q=0;
    while(tree[q]!=-1 && q<tree_size){
        if(ele<tree[q])
        q=2*q+1;
        else
        q=2*q+2;
    }
    if (q>=tree_size)
    printf("tree is full");
    else
    tree[q]=ele;
}

void inorder(int index) {
    if (index >= tree_size || tree[index] == -1) {
        return;
    }
    inorder(2 * index + 1); // Visit left subtree
    printf("%d ", tree[index]); // Visit node
    inorder(2 * index + 2); // Visit right subtree
}

void preorder(int index) {
    if (index >= tree_size || tree[index] == -1) {
        return;
    }
    printf("%d ", tree[index]); // Visit node
    preorder(2 * index + 1); // Visit left subtree
    preorder(2 * index + 2); // Visit right subtree
}

void postorder(int index) {
    if (index >= tree_size || tree[index] == -1) {
        return;
    }
    postorder(2 * index + 1); // Visit left subtree
    postorder(2 * index + 2); // Visit right subtree
    printf("%d ", tree[index]); // Visit node
}

void display(){
    for(int i=0;i<tree_size;i++)
    printf("%d ",tree[i]);
}

int main() {
    for(int i=0;i<7;i++)
    tree[i]=-1;

    insert(100);
    insert(150);
    insert(180);
    insert(30);
    display();
    printf("\nInorder traversal: ");
    inorder(0);
    printf("\n");
    printf("Preorder traversal: ");
    preorder(0);
    printf("\n");
    printf("Postorder traversal: ");
    postorder(0);
    printf("\n");

    return 0;
}