//class 8 ;Circular Singly linked list operations(similar to singly but lastnode->next is head here not NULL)
//                                                (insert/delete after funcs remain same)

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
    if (head == NULL) {
        new_node->next = new_node; // Point to itself for the first node
        head = new_node; // Update the head pointer
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        new_node->next = head; // Point to the current head node
        temp->next = new_node; // Update the next pointer of the last node
        head = new_node; // Update the head pointer
    }
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
    new_node->data = new_data;
    if (head == NULL) {
        new_node->next = new_node; // Point to itself for the first node
        head = new_node; // Update the head pointer
    } else {
        struct Node* temp = head->next;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_node; // Update the next pointer of the last node
        new_node->next = head; // Point back to the head node to maintain circular nature
    }
    return head;
}

// Function to delete a node from the beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct Node* temp = head->next;

    // If the list has only one node
    if (head == head->next) {
        free(head);
        return NULL;
    }

    // Find the last node
    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    // Update the last node's next pointer to the new head
    last->next = temp;

    // Free the old head node
    free(head);

    // Return the new head node
    return temp;
}

// Function to delete a node from a specific position
struct Node* deleteFromPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct Node* temp = head->next;
    if (position == 0) {
        return deleteFromBeginning(head);
    }
    for (int i = 0; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    if (temp->next == head) {
        printf("Position out of range\n");
        return head;
    }
    struct Node* node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    free(node_to_delete);
    return head;
}

// Function to delete a node from the end
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct Node* temp = head->next;
    if (head == head->next) {
        free(head);
        return NULL;
    }
    while (temp->next->next != head) {
        temp = temp->next;
    }
    struct Node* node_to_delete = temp->next;
    temp->next = head;
    free(node_to_delete);
    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head->next;
    printf("%d -> ", head->data);
    while (temp != head) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d -> ", temp->data);
    printf("...\n"); // Print ellipsis to indicate circular nature
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert after a node\n");
        printf("3. Insert at end\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from position\n");
        printf("6. Delete from end\n");
        printf("7. Print list\n");
        printf("8. Exit\n");
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
                head = deleteFromBeginning(head);
                break;
            case 5:
                printf("Enter position to delete (starting from 0): ");
                scanf("%d", &position);
                head = deleteFromPosition(head, position);
                break;
            case 6:
                head = deleteFromEnd(head);
                break;
            case 7:
                printList(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

//try other ways