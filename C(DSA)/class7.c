//class 7 ;Doubly linked list operations
//4th method of doing linked list operations as well; see first 3 in insertion opn for singly linked list operations

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *llink;
  struct Node *rlink;
};

typedef struct Node Node;
typedef struct dLIST{
  Node* head;
}DLIST;

Node *getNode(int ele)
{
  struct Node *newNode;
  newNode=(struct Node*)malloc(sizeof(struct Node));
  newNode->data=ele;
  newNode->rlink=NULL;
  newNode->llink=NULL;
  return newNode; //address is sent
}

void init(DLIST *ptr)
{
    ptr->head=NULL;
}

void insertAtBeginning(DLIST *ptr, int ele)
{
    Node *newNode=getNode(ele);
    if(ptr->head==NULL){
        ptr->head=newNode;
    }
    else{
        newNode->rlink=ptr->head;
        ptr->head->llink=newNode;
        ptr->head=newNode;
    }
}

void insertAtEnd(DLIST *ptr, int ele)
{
    Node *newNode=getNode(ele);
    if(ptr->head==NULL){
        ptr->head=newNode;
    }
    else{
        Node *temp=ptr->head;
        while(temp->rlink!=NULL){
            temp=temp->rlink;
        }
        temp->rlink=newNode;
        newNode->llink=temp;
    }
}

void insertAtPosition(DLIST *ptr, int ele, int pos)
{
    if(ptr->head==NULL || pos==0){
        insertAtBeginning(ptr, ele);
    }
    else{
        Node *newNode=getNode(ele);
        Node *temp=ptr->head;
        for(int i=1; i<pos-1 && temp!=NULL; i++){
            temp=temp->rlink;
        }
        if(temp==NULL){
            printf("Invalid position\n");
        }
        else{
            newNode->rlink=temp->rlink;
            if(temp->rlink!=NULL){
                temp->rlink->llink=newNode;
            }
            newNode->llink=temp;
            temp->rlink=newNode;
        }
    }
}
void deleteAtBeginning(DLIST *ptr)
{
    if(ptr->head==NULL){
        printf("List is empty\n");
    }
    else{
        Node *temp=ptr->head;
        ptr->head=ptr->head->rlink;
        if(ptr->head!=NULL){
            ptr->head->llink=NULL;
        }
        free(temp);
    }
}

void deleteAtEnd(DLIST *ptr)
{
    if(ptr->head==NULL){
        printf("List is empty\n");
    }
    else{
        Node *temp=ptr->head;
        while(temp->rlink!=NULL){
            temp=temp->rlink;
        }
        if(temp->llink!=NULL)//checking if 2 nodes present
        {
            temp->llink->rlink=NULL;
        }
        else{
            ptr->head=NULL;
        }
        free(temp);
    }
}
void deleteAtPosition(DLIST *ptr, int pos)
{
    if(ptr->head==NULL)
    {
        printf("List is empty\n");
    }
    else{
        Node *temp=ptr->head;
        for(int i=1; i<pos && temp!=NULL; i++){
            temp=temp->rlink;
        }
        if(temp==NULL){
            printf("Invalid position\n");
        }
        else{
            temp->llink->rlink=temp->rlink;
            if(temp->rlink!=NULL){
                temp->rlink->llink=temp->llink;
            }
            free(temp);
        }
    }
}
void display(DLIST *ptr)
{
    Node *temp=ptr->head;
    while(temp!=NULL){
        printf("%d ->", temp->data);
        temp=temp->rlink;
    }
    printf("NULL\n");
}

int main()
{
    int choice, data, position;
    DLIST L;
    init(&L);
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6:delete at particular position\n");
        printf("7:print the list\n");
        printf("8.exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                insertAtBeginning(&L, data);
                break;
            case 2:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                insertAtEnd(&L, data);
                break;
            case 3:
                printf("Enter the data to be inserted and position: ");
                scanf("%d %d", &data, &position);
                insertAtPosition(&L, data, position);
                break;
            case 4:
                 deleteAtBeginning(&L);
                break;
            case 5:
                 deleteAtEnd(&L);
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &position);
                deleteAtPosition(&L, position);
                break;
            case 7:
                display(&L);
                break;
            case 8:
                exit(0);
        }
    }
    return 0;
}