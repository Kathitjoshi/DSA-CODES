//Class 6; Code to concatenate two singly linked lists and sum of nodes
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;

struct Node *getNode(int ele) {
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ele;
    newNode->next = NULL;
    return newNode; // address is sent
}

void concatenateLists(Node* list1, Node* list2) {
        Node* temp = list1;

        // Traverse the first linked list until the end
        while (temp->next != NULL) {
                temp = temp->next;
        }

        // Set the next pointer of the last node of the first linked list to the head of the second linked list
        temp->next = list2;
}

void printList(Node* node) {
        while (node != NULL) {
                printf("%d -> ", node->data);
                node = node->next;
        }
        printf("NULL\n");
}

int sumOfNodes(Node* head) {
        int sum = 0;
        Node* temp = head;
        while (temp != NULL) {
                sum += temp->data;
                temp = temp->next;
        }
        return sum;
}

int main() {
        // Create first linked list
        Node* head1 = getNode(1);
        head1->next = getNode(2);
        head1->next->next = getNode(3);
        head1->next->next->next = getNode(4);

        // Create second linked list
        Node* head2 = getNode(5);
        head2->next = getNode(6);
        head2->next->next = getNode(7);
        head2->next->next->next = getNode(8);

        // Concatenate the two linked lists
        concatenateLists(head1, head2);
        printf("Concatenated Linked List: ");
        printList(head1);

        // Find the sum of nodes
        int sum = sumOfNodes(head1);
        printf("Sum of nodes: %d\n", sum);

        return 0;
}