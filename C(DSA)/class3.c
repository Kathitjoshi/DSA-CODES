// // Class 3; Intro to Linked list

// // Node creation and display w/o function

// #include <stdio.h>
// struct Node
// {
//  int data;
//  struct Node *link; //pointer to next node
// };
// int main(void)
// {
// struct Node *ptr;//pointer to Node of linked list
// ptr=(struct Node*)malloc(sizeof(struct Node));//allocate memory for node1
// ptr->data=10;//data of first node
// ptr->link=NULL;
// printf("%d",ptr->data);//prints data of first node
// printf("%p",ptr->link);//printzs address of second node
// return 0;
// }

// Node creation  with function and display w/o function

// #include <stdio.h>
// struct Node
// {
//  int data;
//  struct Node *link; 
// };
// struct Node *getNode(int ele)
// {
//   struct Node *newNode;
//   newNode=(struct Node*)malloc(sizeof(struct Node));
//   newNode->data=ele;
//   newNode->link=NULL;
//   return newNode; //address is sent
// }
// int main(void)
// {
// struct Node *ptr,*newNode,*aux; 
// ptr=getNode(10); //function is called to create node
// newNode=getNode(15);
// ptr->link=newNode;
// aux=ptr;//aux is pointing to first node
// while(aux!=NULL)//while loop to print all nodes
//   {
//     printf("\n %d",aux->data);//prints data of first node
//     aux=aux->link;//aux is pointing to second node
//   }

// return 0;
// }








