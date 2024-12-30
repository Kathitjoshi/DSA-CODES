//Hash table using array and linked list

//array


// #include <stdio.h>

// #define tab_size 10

// typedef struct inventory {
//     int part_id;
//     int no_parts;
//     int flag; // 0: empty, 1: occupied
// } parts;

// // Initialize the hash table
// void init(parts *p) {
//     for (int i = 0; i < tab_size; i++) {
//         p[i].flag = 0;
//     }
// }

// // Insert a part into the hash table
// void insert(parts *p, int id, int no, int *count) {
//     int h_id;

//     if (*count == tab_size) { 
//         printf("Hash table full\n");
//         return;
//     }
    
//     h_id = id % tab_size;

//     // Linear probing
//     while (p[h_id].flag == 1) {
//         h_id = (h_id + 1) % tab_size;
//     }

//     p[h_id].part_id = id;
//     p[h_id].no_parts = no;
//     p[h_id].flag = 1;
//     (*count)++;
// }

// // Display the contents of the hash table
// void display(parts *p) {
//     printf("\nIndex  Part ID  No of Parts");
//     for (int i = 0; i < tab_size; i++) {
//         printf("\n%5d", i);
//         if (p[i].flag == 1) {
//             printf("%8d%12d", p[i].part_id, p[i].no_parts);
//         } else {
//             printf("%20s", "-");
//         }
//     }
//     printf("\n");
// }

// // Search for a part in the hash table
// void search(parts *p, int id, int *count) {
//     int h_id, i = 0;
//     if (*count == 0) {
//         printf("Empty hash table\n");
//         return;
//     }
//     h_id = id % tab_size;

//     // Linear probing
//     while (p[h_id].flag != 0 && i < tab_size) {
//         if (p[h_id].part_id == id) {
//             printf("Part ID = %d, No of Parts = %d\n", p[h_id].part_id, p[h_id].no_parts);
//             return;
//         }
//         h_id = (h_id + 1) % tab_size;
//         i++;
//     }

//     printf("Record not found\n");
// }

// // Delete a part from the hash table
// void delete(parts *p, int id, int *count) {
//     int h_id, i = 0;
//     if (*count == 0) {
//         printf("Empty hash table\n");
//         return;
//     }
//     h_id = id % tab_size;

//     // Linear probing
//     while (p[h_id].flag != 0 && i < tab_size) {
//         if (p[h_id].part_id == id) {
//             p[h_id].flag = 0; // Mark as empty
//             (*count)--; // Decrease count
//             printf("Part ID %d deleted successfully.\n", id);
//             return;
//         }
//         h_id = (h_id + 1) % tab_size;
//         i++;
//     }

//     printf("Record not found\n");
// }

// int main() {
//     int ch, id, no, count = 0;
//     parts ht[tab_size];
//     init(ht);

//     do {
//         printf("\nEnter 1: Insert, 2: Display, 3: Search, 4: Delete, 5: Exit: ");
//         scanf("%d", &ch);
//         switch (ch) {
//             case 1:
//                 printf("Enter part ID and number of parts: ");
//                 scanf("%d %d", &id, &no);
//                 insert(ht, id, no, &count);
//                 break;
//             case 2:
//                 display(ht);
//                 break;
//             case 3:
//                 printf("Enter part ID: ");
//                 scanf("%d", &id);
//                 search(ht, id, &count);
//                 break;
//             case 4:
//                 printf("Enter part ID to delete: ");
//                 scanf("%d", &id);
//                 delete(ht, id, &count);
//                 break;
//             case 5:
//                 printf("Exiting...\n");
//                 break;
//             default:
//                 printf("Invalid option. Please try again.\n");
//         }
//     } while (ch != 5);

//     return 0;
// }

//linked list

#include <stdio.h>
#include <stdlib.h>

#define TAB_SIZE 10

// Part structure
struct Part {
    int part_id;
    int no_parts;
    struct Part *link;
};

// Initialize the hash table
void init(struct Part *table[]) {
    for (int i = 0; i < TAB_SIZE; i++) {
        table[i] = NULL;
    }
}

// Hash function
int hashFunction(int id) {
    return id % TAB_SIZE;
}

// Insert function
void insert(struct Part *table[], int id, int no) {
    int index = hashFunction(id);
    struct Part *newNode = (struct Part *)malloc(sizeof(struct Part));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->part_id = id;
    newNode->no_parts = no;
    newNode->link = table[index];
    table[index] = newNode;

    printf("Part inserted successfully.\n");
}

// Display function
void display(struct Part *table[]) {
    for (int i = 0; i < TAB_SIZE; i++) {
        printf("Index %d: ", i);
        struct Part *temp = table[i];
        if (temp == NULL) {
            printf("Empty");
        } else {
            while (temp != NULL) {
                printf("-> [ID: %d, Parts: %d] ", temp->part_id, temp->no_parts);
                temp = temp->link;
            }
        }
        printf("\n");
    }
}

// Search function
void search(struct Part *table[], int id) {
    int index = hashFunction(id);
    struct Part *temp = table[index];
    while (temp != NULL) {
        if (temp->part_id == id) {
            printf("Part found - ID: %d, Number of parts: %d\n", temp->part_id, temp->no_parts);
            return;
        }
        temp = temp->link;
    }
    printf("Part ID %d not found.\n", id);
}

// Delete function
void delete(struct Part *table[], int id) {
    int index = hashFunction(id);
    struct Part *temp = table[index];

    if (temp == NULL) {
        printf("Part ID %d not found.\n", id);
        return;
    }

    if (temp->part_id == id) {
        table[index] = temp->link;
        free(temp);
        printf("Part ID %d deleted successfully.\n", id);
        return;
    }

    while (temp->link != NULL) {
        if (temp->link->part_id == id) {
            struct Part *toDelete = temp->link;
            temp->link = toDelete->link;
            free(toDelete);
            printf("Part ID %d deleted successfully.\n", id);
            return;
        }
        temp = temp->link;
    }

    printf("Part ID %d not found.\n", id);
}

int main() {
    int ch, id, no;
    struct Part *table[TAB_SIZE];
    init(table);

    do {
        printf("\nEnter 1: Insert, 2: Display, 3: Search, 4: Delete, 5: Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter part ID and number of parts: ");
                scanf("%d %d", &id, &no);
                insert(table, id, no);
                break;
            case 2:
                display(table);
                break;
            case 3:
                printf("Enter part ID: ");
                scanf("%d", &id);
                search(table, id);
                break;
            case 4:
                printf("Enter part ID to delete: ");
                scanf("%d", &id);
                delete(table, id);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (ch != 5);

    return 0;
}