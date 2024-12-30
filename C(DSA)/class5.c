// // // Class 5; Deletion operations on singly linked list(including one insertion operation for clarity)

// //1 with single pointer

#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
};
struct Node *insertAtBeginning(struct Node *head, int new_data) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = head;
  head = new_node;
  return head;
}



struct Node *deleteAtPosition(struct Node *head, int position) {
    if (head == NULL) {
        return NULL; // List is empty
    }

    struct Node *temp = head;

    // If head needs to be removed
    if (position == 0) {
        head = temp->next; // Change head
        free(temp); // Free old head
        return head;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL) {
        return head;
    }

    // Node temp->next is the node to be deleted
    struct Node *next = temp->next->next;

    free(temp->next); // Free memory

    temp->next = next; // Unlink the deleted node from list

    return head;
}

struct Node *deleteFront(struct Node *head) {
  if (head == NULL)
    return NULL; // List is empty
  struct Node *temp = head;
  head = head->next;
  free(temp);
  return head;
}

struct Node *deleteEnd(struct Node *head) {
  if (head == NULL)
    return NULL;            // List is empty
  if (head->next == NULL) { // Only one node in the list
    free(head);
    return NULL;
  }
  struct Node *temp = head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
  return head;
}
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
  struct Node *head = NULL;
  int choice, data, position;

  while (1) {
    printf("\nMenu:\n");
    printf("1. Insert at beginning\n");
    printf("2. Delete at beginning\n");
    printf("3. Delete at end\n");
    printf("4:print the list\n");
    printf("5:delete at particular position\n");
    printf("6.exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter data to insert at beginning: ");                
      scanf("%d", &data);
      head = insertAtBeginning(head, data);
      break;
    case 2:
      head = deleteFront(head);
      break;
    case 3:
      head = deleteEnd(head);
      break;
     case 4:
       printList(head);
      break;
      case 5:
        printf("Enter position to delete: ");
        scanf("%d", &position);
        head = deleteAtPosition(head, position);
        break;
      case 6:
         exit(0);
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}



//2 with double pointer

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

// void delete_front(struct Node** head_ref) {
//     if (*head_ref == NULL) return;
//     struct Node* temp = *head_ref;
//     *head_ref = (*head_ref)->next;
//     free(temp);
// }

// void delete_end(struct Node** head_ref) {
//     if (*head_ref == NULL) return;
//     if ((*head_ref)->next == NULL) {
//         free(*head_ref);
//         *head_ref = NULL;
//         return;
//     }
//     struct Node* second_last = *head_ref;
//     while (second_last->next->next != NULL) {
//         second_last = second_last->next;
//     }
//     free(second_last->next);
//     second_last->next = NULL;
// }
// void deleteAtPosition(struct Node** head_ref, int position) {//+
//     if (*head_ref == NULL) return;//+
// //+
//     struct Node* temp = *head_ref;//+
// //+
//     if (position == 0) {//+
//         *head_ref = temp->next;//+
//         free(temp);//+
//         return;//+
//     }//+
// //+
//     for (int i = 0; temp != NULL && i < position - 1; i++) {//+
//         temp = temp->next;//+
//     }//+
// //+
//     if (temp == NULL || temp->next == NULL) return;//+
// //+
//     struct Node* next = temp->next->next;//+
//     free(temp->next);//+
//     temp->next = next;
// }


// void display(struct Node* node) {
//     while (node != NULL) {
//         printf("%d -> ", node->data);
//         node = node->next;
//     }
//     printf("NULL\n");
// }

// int main() {
//   struct Node *head = NULL;
//   int choice, data, position;

//   while (1) {
//     printf("\nMenu:\n");
//     printf("1. Insert at beginning\n");
//     printf("2. Delete at beginning\n");
//     printf("3. Delete at end\n");
//     printf("4:print the list\n");
//     printf("5:deleta t a position\n");
//     printf("6.exit\n");
//     printf("\nEnter your choice: ");
//     scanf("%d", &choice);
//     switch (choice) {
//     case 1:
//       printf("Enter data to insert at beginning: ");                
//       scanf("%d", &data);
//       insertAtBeginning(&head, data);
//       break;
//     case 2:
//       delete_front(&head);
//       break;
//     case 3:
//       delete_end(&head);
//       break;
//      case 4:
//        display(head);
//       break;
//       case 5:
//        printf("Enter position to delete: ");
//        scanf("%d", &position);
//        deleteAtPosition(&head, position);
//        break;
//       case 6:
//          exit(0);
//     default:
//       printf("Invalid choice\n");
//     }
//   }
//   return 0;
// }


// //try third way for this






