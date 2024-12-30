//Circular Queue by array/linked list

//array

// #include <stdio.h>

// #define MAX_SIZE 100

// typedef struct {
//     int front, rear;
//     int size;
//     int arr[MAX_SIZE];
// } CircularQueue;

// void initQueue(CircularQueue *q) {
//     q->front = q->rear = -1;
//     q->size = 0;
// }

// int isFull(CircularQueue *q) {
//     return (q->size == MAX_SIZE);
// }

// int isEmpty(CircularQueue *q) {
//     return (q->size == 0);
// }

// void enqueue(CircularQueue *q, int value) {
//     if (isFull(q)) {
//         printf("Queue is full\n");
//         return;
//     }
//     if (isEmpty(q)) {
//         q->front = 0;
//     }
//     q->rear = (q->rear + 1) % MAX_SIZE;
//     q->arr[q->rear] = value;
//     q->size++;
// }

// int dequeue(CircularQueue *q) {
//     if (isEmpty(q)) {
//         printf("Queue is empty\n");
//         return -1;
//     }
//     int value = q->arr[q->front];
//     if (q->front == q->rear) {
//         q->front = q->rear = -1;
//     } else {
//         q->front = (q->front + 1) % MAX_SIZE;
//     }
//     q->size--;
//     return value;
// }



// void display(CircularQueue *q) {
//     if (isEmpty(q)) {
//         printf("Queue is empty\n");
//         return;
//     }
//     int i = q->front;
//     printf("Queue: ");
//     while (i != q->rear) {
//         printf("%d ", q->arr[i]);
//         i = (i + 1) % MAX_SIZE;
//     }
//     printf("%d\n", q->arr[i]);
// }

// int main() {
//     CircularQueue q;
//     initQueue(&q);
    
//     int choice, value;
    
//     do {
//         printf("1. Enqueue\n");
//         printf("2. Dequeue\n");
//         printf("3. Display\n");
//         printf("0. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);
        
//         switch (choice) {
//             case 1:
//                 printf("Enter the value to enqueue: ");
//                 scanf("%d", &value);
//                 enqueue(&q, value);
//                 break;
//             case 2:
//                 value = dequeue(&q);
//                 if (value != -1) {
//                     printf("Dequeued value: %d\n", value);
//                 }
//                 break;
//             case 3:
//                 display(&q);
//                 break;
//             case 0:
//                 printf("Exiting...\n");
//                 break;
//             default:
//                 printf("Invalid choice\n");
//         }
        
//         printf("\n");
//     } while (choice != 0);
    
//     return 0;
// }

//linked list

#include <stdio.h>
#define MAX_SIZE 100

#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct CircularQueue {
    Node* front;
    Node* rear;
    int size;
} CircularQueue;

void initQueue(CircularQueue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

int isFull(CircularQueue* q) {
    return (q->size == MAX_SIZE);
}

int isEmpty(CircularQueue* q) {
    return (q->size == 0);
}

void enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->rear->next = q->front; // Connect rear to front for circular queue
    q->size++;
}

int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->front->data;
    Node* temp = q->front;
    if (q->front == q->rear) {
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
        q->rear->next = q->front; // Update rear's next pointer
    }
    free(temp);
    q->size--;
    return value;
}

void display(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
    printf("\n");
}

int main() {
    CircularQueue q;
    initQueue(&q);
    
    int choice, value;
    
    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                display(&q);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
        
        printf("\n");
    } while (choice != 0);
    
    return 0;
}