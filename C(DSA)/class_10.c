//Operations on stack by array/linked list implementation

//array 

// #include <stdio.h>
// #include <stdlib.h>

// #define STACK_SIZE 10

// struct Stack {
//     int top;
//     int items[STACK_SIZE];
// };

// void push(struct Stack *s, int item) {
//     if (s->top == STACK_SIZE - 1) {
//         printf("Stack Overflow\n");
//         return;
//     }
//     s->top++;
//     s->items[(s->top)] = item;
// }

// int pop(struct Stack *s) {
//     if (s->top == -1) {
//         printf("Stack Underflow\n");
//         return -1;
//     }
//     return s->items[s->top--];
// }

// void empty_stack(struct Stack *s) {
//     if (s->top == -1) {
//         printf("Stack is empty\n");
//         return;
//     }
//     else{
//         printf("Stack isn't empty\n");
//     }
    
// }
// void overflow(struct Stack *s) {
//     if (s->top == STACK_SIZE - 1) {
//         printf("Stack is full\n");
//         return;
//     }
//     else{
//         printf("Stack is not full\n");
//     }
// }
// void display(struct Stack *s) {
//     if (s->top == -1) {
//         printf("Stack is empty\n");
//         return;
//     }
//     for (int i = s->top; i>=0; i--) {
//         printf("%d ", s->items[i]);
//     }
//     printf("\n");
// }

// int main() {
//     struct Stack s;
//     s.top = -1;
//     int choice, ele;
//     while(1){
//     printf("\n");
//     printf("Menu\n");
//     printf("1. Push items\n");
//     printf("2. Pop items\n");
//     printf("3. Display items\n");
//     printf("4. Empty Stack check\n");
//     printf("5.Overflow check\n");
//     printf("6. Exit\n");
//     printf("Enter choice number: ");
//     scanf("%d", &choice);
    
//     switch (choice) {
//         case 1:
//             printf("Enter element to push: ");
//             scanf("%d", &ele);
//             push(&s, ele);
//             break;
//         case 2:
//             ele = pop(&s);
//             if (ele != -1) {
//                 printf("Popped element: %d\n", ele);
//             }
//             break;
//         case 3:
//             display(&s);
//             break;
//         case 4:
//               empty_stack(&s);
//               break;
//         case 5:
//               overflow(&s);
//               break;          
//         case 6:
//             exit(0);
//         default:
//             printf("Invalid choice\n");
//     }
//     }
//     return 0;
// }

//linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = item;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void empty_stack(struct Node** top) {
    while (*top != NULL) {
        pop(top);
    }
    printf("Stack emptied\n");
}

void overflow(struct Node** top) {
    printf("Stack overflow check is not applicable for linked list implementation\n");
}

int main() {
    struct Node* top = NULL;
    int choice, ele;

    while (1) {
        printf("Menu\n");
        printf("1. Push items\n");
        printf("2. Pop items\n");
        printf("3. Display items\n");
        printf("4. Empty stack\n");
        printf("5. Overflow check\n");
        printf("6. Exit\n");
        printf("Enter choice number: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &ele);
                push(&top, ele);
                break;
            case 2:
                ele = pop(&top);
                if (ele != -1) {
                    printf("Popped element: %d\n", ele);
                }
                break;
            case 3:
                display(top);
                break;
            case 4:
                empty_stack(&top);
                break;
            case 5:
                overflow(&top);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
