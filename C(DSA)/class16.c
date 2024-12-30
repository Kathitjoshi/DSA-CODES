//Ascending priority queue(remove element at 1st priority) implementation using array/LL

//ARRAY

#include <stdio.h>

// Priority queue implementation with selection sort
struct pqueue
{
    int data;
    int pty;
};

struct pqueue pq[10];

void pqinsert(int x, int pty, struct pqueue *pq, int *count)
{
    // x is item to be inserted
    // pty is the priority of the item
    // pq is the pointer to the priority queue
    // count is the number of items in the queue

    int j;
    struct pqueue key;
    key.data = x;
    key.pty = pty;
    pq[*count] = key; // insert the element at the end
    (*count)++;

    // Bubble sort to sort the priority queue based on priority
    for (int i = 0; i < *count - 1; i++) {
        for (int j = 0; j < *count - i - 1; j++) {
            if (pq[j].pty > pq[j + 1].pty) {
                // Swap the elements
                struct pqueue temp = pq[j];
                pq[j] = pq[j + 1];
                pq[j + 1] = temp;
            }
        }
    }
}

struct pqueue pqdelete(struct pqueue *pq, int *count)
{
    // pq is a pointer to the priority queue
    // count is the number of elements in the queue

    int i;
    struct pqueue key;

    // if queue is empty, return a structure with priority -1
    if (*count == 0)
    {
        key.data = 0;
        key.pty = -1;
    }
    // delete the first item
    // shift the other items to the left
    else
    {
        key = pq[0];
        for (i = 1; i <= *count - 1; i++)
            pq[i - 1] = pq[i];
        (*count)--;
    }
    return key; // return the key with the lowest priority
}

int main()
{
    int count = 0;

    // Call the functions here
    pqinsert(5, 2, pq, &count);
    pqinsert(10, 1, pq, &count);
    pqinsert(3, 3, pq, &count);

    struct pqueue deletedItem = pqdelete(pq, &count);

    printf("Deleted item: %d with priority: %d\n", deletedItem.data, deletedItem.pty);

    return 0;
}




//Linked list


// #include <stdio.h>
// #include <stdlib.h>
// struct Node {
//     int data;
//     int pty;
//     struct Node* next;
// };

// // Function to insert a node in priority queue using linked list
// void pqinsert(int x, int pty, struct Node** head) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = x;
//     newNode->pty = pty;
//     newNode->next = NULL;

//     if (*head == NULL || (*head)->pty > pty) {
//         newNode->next = *head;
//         *head = newNode;
//     } else {
//         struct Node* current = *head;
//         while (current->next != NULL && current->next->pty <= pty) {
//             current = current->next;
//         }
//         newNode->next = current->next;
//         current->next = newNode;
//     }
// }

// // Function to delete a node from priority queue using linked list
// struct Node* pqdelete(struct Node** head) {
//     if (*head == NULL) {
//         return NULL;
//     }

//     struct Node* temp = *head;
//     *head = (*head)->next;
//     return temp;
// }

// // Usage example
// int main() {
//     struct Node* head = NULL;

//     pqinsert(5, 2, &head);
//     pqinsert(10, 1, &head);
//     pqinsert(3, 3, &head);

//     struct Node* deletedNode = pqdelete(&head);

//     printf("Deleted item: %d with priority: %d\n", deletedNode->data, deletedNode->pty);

//     free(deletedNode);

//     return 0;
// }