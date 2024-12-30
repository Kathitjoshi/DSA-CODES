// Revision class 2 on recursion, structures and functions, Dynamic Memory allocation

/*#include <stdio.h>
int fact(int n)
{
  if (n==0)
  {
    return 1;
  }
  else
  {
    return n*fact(n-1);
  }
}
int main(void)
{
  int res;
  res=fact(5);
  printf("%d",res);
  return 0;
}*/

/*#include <stdio.h>
struct Student {
  int roll_no;
  int marks;
};
void display(struct Student s) {
  printf("Roll No: %d\n", s.roll_no);
  printf("Marks: %d\n", s.marks);
}
int main(void) {
  struct Student s;
  printf("Enter Roll No: ");
  scanf("%d", &s.roll_no);
  printf("Enter Marks: ");
  scanf("%d", &s.marks);
  display(s);
  return 0;
}*/


// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
//   int *ptr;
//   ptr=(int*)malloc(sizeof(int));
//   printf("%d ptr:" ,*ptr);
//   printf("enter the value of p\n");
//   scanf("%d",ptr);
//   printf("\n The value:%d" ,*ptr);
//   free(ptr);
//   return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
//   int *ptr,n=3;
//   ptr=(int*)malloc(sizeof(int));
//   for(int i=0;i<3;i++){
//      printf("%d ptr:" ,*(ptr+i));
//   }
//   printf("enter the value of p\n");
//   for (int i=0;i<3;i++)
//     {
//   scanf("%d",(ptr+i));
//     }
//   for(int i=0;i<3;i++)
//     {
//   printf("\n The value:%d" ,*(ptr+i));
//     }
//   free(ptr);
//   return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
//   int *ptr,n=3;
//   ptr=(int*)calloc(3,sizeof(int));
//   for(int i=0;i<3;i++){
//      printf("%d ptr:" ,*(ptr+i));
//   }
//   printf("enter the value of p\n");
//   for (int i=0;i<3;i++)
//     {
//   scanf("%d",(ptr+i));
//     }
//   for(int i=0;i<3;i++)
//     {
//   printf("\n The value:%d" ,*(ptr+i));
//     }
//   free(ptr);
//   return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
//   int *ptr,n=3,*ptr_new;
//   ptr=(int*)calloc(3,sizeof(int));
//   ptr_new=(int*)realloc(ptr,2*sizeof(int));
//   for(int i=0;i<3;i++){
//      printf("%d ptr_new:" ,*(ptr_new+i));
//   }
//   printf("enter the value of p\n");
//   for (int i=0;i<3;i++)
//     {
//   scanf("%d",(ptr_new+i));
//     }
//   for(int i=0;i<3;i++)
//     {
//   printf("\n The value:%d" ,*(ptr_new+i));
//     }
//   free(ptr);
//   return 0;
// }
