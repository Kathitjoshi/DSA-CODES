// Class 4; Insertion operations on singly linked list

// 1 With single pointer(you need to return the value )

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning
struct Node* insertAtBeginning(struct Node* head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
    return head;
}

// Function to insert a node after a given node
struct Node* insertAfter(struct Node* head, int position, int new_data) {
    struct Node* temp = head;
    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return head;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

// Function to insert a node at the end
struct Node* insertAtEnd(struct Node* head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = head;
    new_node->data = new_data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        return head;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return head;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert after a node\n");
        printf("3. Insert at end\n");
        printf("4. Print list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert after (starting from 0): ");
                scanf("%d", &position);
                head = insertAfter(head, position, data);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

// 2 With double pointer(you don't need to return the value and use *<var> to access its value in function)


// #include <stdio.h>
// #include <stdlib.h>

// // Define the structure for a linked list node
// struct Node {
//     int data;
//     struct Node* next;
// };

// // Function to insert a node at the beginning
// void insertAtBeginning(struct Node** head_ref, int new_data) {
//     struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
//     new_node->data = new_data;
//     new_node->next = (*head_ref);
//     (*head_ref) = new_node;
// }

// // Function to insert a node after a given node
// void insertAfter(struct Node* prev_node, int new_data) {
//     if (prev_node == NULL) {
//         printf("The given previous node cannot be NULL\n");
//         return;
//     }
//     struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
//     new_node->data = new_data;
//     new_node->next = prev_node->next;
//     prev_node->next = new_node;
// }

// // Function to insert a node at the end
// void insertAtEnd(struct Node** head_ref, int new_data) {
//     struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
//     struct Node* last = *head_ref;
//     new_node->data = new_data;
//     new_node->next = NULL;
//     if (*head_ref == NULL) {
//         *head_ref = new_node;
//         return;
//     }
//     while (last->next != NULL) {
//         last = last->next;
//     }
//     last->next = new_node;
// }

// // Function to print the linked list
// void printList(struct Node* node) {
//     while (node != NULL) {
//         printf("%d -> ", node->data);
//         node = node->next;
//     }
//     printf("NULL\n");
// }

// // Main function to display the menu and perform operations
// int main() {
//     struct Node* head = NULL;
//     int choice, data, pos;

//     while (1) {
//         printf("\nMenu:\n");
//         printf("1. Insert at beginning\n");
//         printf("2. Insert after a node\n");
//         printf("3. Insert at end\n");
//         printf("4. Print list\n");
//         printf("5. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("Enter data to insert at beginning: ");
//                 scanf("%d", &data);
//                 insertAtBeginning(&head, data);
//                 break;
//             case 2:
//                 printf("Enter data to insert: ");
//                 scanf("%d", &data);
//                 printf("Enter position after which to insert (0 for head): ");
//                 scanf("%d", &pos);
//                 struct Node* temp = head;
//                 for (int i = 0; i < pos && temp != NULL; i++) {
//                     temp = temp->next;
//                 }
//                 if (temp != NULL) {
//                     insertAfter(temp, data);
//                 } else {
//                     printf("Position out of range\n");
//                 }
//                 break;
//             case 3:
//                 printf("Enter data to insert at end: ");
//                 scanf("%d", &data);
//                 insertAtEnd(&head, data);
//                 break;
//             case 4:
//                 printList(head);
//                 break;
//             case 5:
//                 exit(0);
//             default:
//                 printf("Invalid choice\n");
//         }
//     }

//     return 0;
// }

// 3 using typedef for struct type and struct* type 

// #include <stdio.h>
// #include <stdlib.h>

// // Define the structure for a linked list node
// struct Node {
//     int data;
//     struct Node* next;
// };
// typedef struct Node node;
// typedef struct Node* list;

// // Function to insert a node at the beginning
// list insertAtBeginning(list ptr, int new_data) {
//     node * new_node = (node*)malloc(sizeof(node));
//     new_node->data = new_data;
//     new_node->next = ptr;
//     ptr = new_node;
//     return ptr;
// }

// // Function to insert a node after a given node
// list insertAfter(list ptr, int position, int new_data) {
//     node* temp = ptr;
//     for (int i = 0; i < position && temp != NULL; i++) {
//         temp = temp->next;
//     }
//     if (temp == NULL) {
//         printf("Position out of range\n");
//         return ptr;
//     }
//     node* new_node = (node*)malloc(sizeof(node));
//     new_node->data = new_data;
//     new_node->next = temp->next;
//     temp->next = new_node;
//     return ptr;
// }

// // Function to insert a node at the end
// list insertAtEnd(list ptr, int new_data) {
//     node* new_node = (node*)malloc(sizeof(node));
//     node* last = ptr;
//     new_node->data = new_data;
//     new_node->next = NULL;
//     if (ptr == NULL) {
//         ptr = new_node;
//         return ptr;
//     }
//     while (last->next != NULL) {
//         last = last->next;
//     }
//     last->next = new_node;
//     return ptr;
// }

// // Function to print the linked list
// void printList(node* node) {
//     while (node != NULL) {
//         printf("%d -> ", node->data);
//         node = node->next;
//     }
//     printf("NULL\n");
// }

// int main() {
//     list L1 = NULL;
//     int choice, data, position;

//     while (1) {
//         printf("\nMenu:\n");
//         printf("1. Insert at beginning\n");
//         printf("2. Insert after a node\n");
//         printf("3. Insert at end\n");
//         printf("4. Print list\n");
//         printf("5. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("Enter data to insert at beginning: ");
//                 scanf("%d", &data);
//                 L1 = insertAtBeginning(L1, data);
//                 break;
//             case 2:
//                 printf("Enter data to insert: ");
//                 scanf("%d", &data);
//                 printf("Enter position to insert after (starting from 0): ");
//                 scanf("%d", &position);
//                 L1 = insertAfter(L1, position, data);
//                 break;
//             case 3:
//                 printf("Enter data to insert at end: ");
//                 scanf("%d", &data);
//                 L1 = insertAtEnd(L1, data);
//                 break;
//             case 4:
//                 printList(L1);
//                 break;
//             case 5:
//                 exit(0);
//             default:
//                 printf("Invalid choice\n");
//         }
//     }

//     return 0;
// }