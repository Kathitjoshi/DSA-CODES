// // Queue implementation using array/linked list

// //array

#include<stdio.h>
#define SIZE 3

typedef struct queue{
    int array[SIZE];
    int f;
    int r;
}Queue;

void init(Queue *q){
    q->f=-1;
    q->r=-1;
}
int isEmpty(Queue q){
    return(q.r==q.f && q.f==-1);
}
int isOneElement(Queue q){
    return(q.r==q.f && q.f!=-1);
}
int isFull(Queue q){
    return(q.r==SIZE-1);
}
void Enqueue(Queue *q,int d){
    if(isEmpty(*q)){
        q->r=q->f=0; //First element of the queue
        q->array[q->r]=d;
    }
    else if(isFull(*q))
        printf("\nQueue is full;Cannot insert");
    else{
        ++(q->r);
        q->array[q->r]=d;
        }
}
void Dequeue(Queue *q){
    if(isEmpty(*q)){
         printf("\nQueue is Empty;Cannot delete");
    }
    else if(isOneElement(*q)){
        q->f=q->r=-1;
    }
    else{
        ++(q->f);
        }
}
void display(Queue q){
    if(!isEmpty(q)){
        printf("\n");
        for(int i=q.f;i<=q.r;i++)
            printf("%d ",q.array[i]);
    }
    else
        printf("\nQueue is Empty");
}
void main(){
    Queue q;
    init(&q);
    int choice, value;
    while (1) {
        printf("Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                Enqueue(&q, value);
                break;
            case 2:
                Dequeue(&q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// // Linked list implementation

// typedef struct Node {
//     int data;
//     struct Node* next;
// } Node;

// typedef struct Queue {
//     Node* front;
//     Node* rear;
// } Queue;

// void initialize(Queue* q) {
//     q->front = q->rear = NULL;
// }

// int isEmpty(Queue* q) {
//     return q->front == NULL;
// }

// void enqueue(Queue* q, int value) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     if (newNode == NULL) {
//         printf("Memory error\n");
//         return;
//     }
//     newNode->data = value;
//     newNode->next = NULL;
//     if (isEmpty(q)) {
//         q->front = q->rear = newNode;
//     } else {
//         q->rear->next = newNode;
//         q->rear = newNode;
//     }
// }

// int dequeue(Queue* q) {
//     if (isEmpty(q)) {
//         printf("Queue is empty. Cannot dequeue\n");
//         return -1;
//     }
//     int value = q->front->data;
//     Node* temp = q->front;
//      if (q->front == q->rear) {
//         q->front = q->rear = NULL;
//     }
//     q->front = q->front->next;
//     free(temp);

//     return value;
// }

// void display(Queue* q) {
//     if (isEmpty(q)) {
//         printf("Queue is empty\n");
//         return;
//     }
//     printf("Queue elements: ");
//     Node* temp = q->front;
//     while (temp != NULL) {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
// }

// int main() {
//     Queue q;
//     int choice, value;
//     initialize(&q); // Initialize the queue before using it
//     while (1) {
//         printf("Queue Operations:\n");
//         printf("1. Enqueue\n");
//         printf("2. Dequeue\n");
//         printf("3. Display\n");
//         printf("4. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("Enter the value to enqueue: ");
//                 scanf("%d", &value);
//                 enqueue(&q, value);
//                 break;
//             case 2:
//                 dequeue(&q);
//                 break;
//             case 3:
//                 display(&q);
//                 break;
//             case 4:
//                 exit(0);
//             default:
//                 printf("Invalid choice. Please try again.\n");
//         }
//     }

//     return 0;
// }