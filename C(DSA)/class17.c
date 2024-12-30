//Dequeue(insertion and deletion at both ends of queue) implementation by array/LL

//array

// #include<stdio.h>
// #define SIZE 3

// typedef struct queue{
//     int array[SIZE];
//     int f;
//     int r;
// }Queue;

// void init(Queue *q){
//     q->f=-1;
//     q->r=-1;
// }
// int isEmpty(Queue q){
//     return(q.r==q.f && q.f==-1);
// }
// int isOneElement(Queue q){
//     return(q.r==q.f && q.f!=-1);
// }
// int isFull(Queue q){
//     return(q.r==SIZE-1 || q.r+1==q.f);
// }
// void InsertRear(Queue *q,int d){
//     if(isEmpty(*q)){
//         q->r=q->f=0; //First element of the queue
//         q->array[q->r]=d;
//     }
//     else if(isFull(*q))
//         printf("\nQueue is full;Cannot insert");
//     else{
//         ++(q->r);
//         q->array[q->r]=d;
//         }
// }
// void InsertFront(Queue *q,int d){
//     if(isEmpty(*q)){
//         q->r=q->f=0; //First element of the queue
//         q->array[q->r]=d;
//     }
//     else if(isFull(*q))
//         printf("\nQueue is full;Cannot insert");
//     else{
//         if(q->f==0)
//             q->f=SIZE-1;
//         else
//             (q->f)--;
//         q->array[q->f]=d;
//         }
// }
// void DeleteFront(Queue *q){
//     if(isEmpty(*q)){
//          printf("\nQueue is Empty;Cannot delete");
//     }
//     else if(isOneElement(*q)){
//         q->f=q->r=-1;
//     }
//     else{
//         if(q->f==SIZE-1)
//             q->f=0;
//         else
//             ++(q->f);
//         }
// }
// void DeleteRear(Queue *q){
//     if(isEmpty(*q)){
//          printf("\nQueue is Empty;Cannot delete");
//     }
//     else if(isOneElement(*q)){
//         q->f=q->r=-1;
//     }
//     else{
//         --(q->r);
//         }
// }
// void display(Queue q){
//     if(!isEmpty(q)){
//         printf("\n");
//         if(q.f>q.r){
//             for(int i=q.f;i<=SIZE-1;i++)
//                 printf("%d ",q.array[i]);
//             for(int i=0;i<=q.r;i++)
//                 printf("%d ",q.array[i]);
//         }
//         else{
//             for(int i=q.f;i<=q.r;i++)
//                 printf("%d ",q.array[i]);
//         }
//     }
//     else
//         printf("\nQueue is Empty");
// }
// void main(){
//     Queue q;
//     init(&q);
//     DeleteRear(&q);
//     display(q);
//     InsertFront(&q,5);
//     display(q);
//     InsertFront(&q,15);
//     display(q);
//     InsertRear(&q,25);
//     display(q);
//     InsertRear(&q,35);
//     display(q);
//     DeleteFront(&q);
//     display(q);
//     DeleteFront(&q);
//     display(q);
//     DeleteRear(&q);
//     display(q);
//     DeleteRear(&q);
//     display(q);
// }

//Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void init(Queue* q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue q) {
    return (q.front == NULL);
}

int isOneElement(Queue q) {
    return (q.front != NULL && q.front == q.rear);
}

void InsertRear(Queue* q, int d) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = d;
    newNode->next = NULL;

    if (isEmpty(*q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void InsertFront(Queue* q, int d) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = d;
    newNode->next = NULL;

    if (isEmpty(*q)) {
        q->front = q->rear = newNode;
    } else {
        newNode->next = q->front;
        q->front = newNode;
    }
}

void DeleteFront(Queue* q) {
    if (isEmpty(*q)) {
        printf("\nQueue is Empty;Cannot delete");
    } else if (isOneElement(*q)) {
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
}

void DeleteRear(Queue* q) {
    if (isEmpty(*q)) {
        printf("\nQueue is Empty;Cannot delete");
    } else if (isOneElement(*q)) {
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        Node* temp = q->front;
        while (temp->next != q->rear) {
            temp = temp->next;
        }
        free(q->rear);
        q->rear = temp;
        q->rear->next = NULL;
    }
}

void display(Queue q) {
    if (!isEmpty(q)) {
        printf("\n");
        Node* temp = q.front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    } else {
        printf("\nQueue is Empty");
    }
}

int main() {
    Queue q;
    init(&q);
    DeleteRear(&q);
    display(q);
    InsertFront(&q, 5);
    display(q);
    InsertFront(&q, 15);
    display(q);
    InsertRear(&q, 25);
    display(q);
    InsertRear(&q, 35);
    display(q);
    DeleteFront(&q);
    display(q);
    DeleteFront(&q);
    display(q);
    DeleteRear(&q);
    display(q);
    DeleteRear(&q);
    display(q);

    return 0;
}
