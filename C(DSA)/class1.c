/* revision class on  an array to structures, pass by value/ref, double pointer, pointer to a structure */

/* #include <stdio.h>
struct Student {
  int roll_no;
  float marks;
  char name[10];
};
int main(void) {
  struct Student s[3];
  for (int i = 0; i < 3; i++) {
    printf("Enter the roll no. , marks of student and name %d\n", i + 1);
    scanf("%d %f %s", &s[i].roll_no, &s[i].marks, s[i].name);
  }
  for (int i = 0; i < 3; i++) {
    printf("the marks is %f\n", s[i].marks);
    printf("the roll no is %d\n", s[i].roll_no);
    printf("the name  is %s\n", s[i].name);
    print("\n -------");
  }
  return 0;
}*/

/*#include <stdio.h>
void pass_by_val(int x, int y) {
  x = x + 10;
  y = y + 10;
}
void pass_by_ref(int *x, int *y) {
  *x = *x + 10;
  *y = *y + 10;
}
int main(void) {
  int a = 100, b = 200;
  pass_by_val(a, b);
  printf("a=%d b= %d\n", a, b);
  int c = 100, d = 200;
  pass_by_ref(&c, &d);
  printf("c=%d d= %d\n", c, d);
}/*

/*include <stdio.h>  
int main(void) {  
  int a = 10;  
  int *p;  
  p = &a;  
  printf("%d \n", *p);   //value of a  
  printf("%p \n", &p);  //memory of p  
  printf("%p \n", p);  //memory of a  
  int **q;  
  q = &p;  
  printf("%d \n", **q); //value of a  
  printf("%p \n", q); //memory of p 
  printf("%p \n", *q); //memory of a
  printf("%p \n", &q); //memory of q
  return 0;  
}*/

/*#include <stdio.h>
struct Student
{
  int roll_no;
  float marks;
  char name[10];
};
int main(void) {
  struct Student s[3], *ptr;
  ptr = &s;
  for (int i = 0; i < 3; i++) {
    printf("Enter the roll no ,marks and name of student %d\n", i + 1);
    scanf("%d %f %s", &ptr->roll_no, &ptr->marks, ptr->name);
    ptr++;

  }
  for (int i = 0; i < 3; i++) {
    printf("the marks is %f\n", ptr->marks);
    printf("the roll no is %d\n", ptr->roll_no);
    printf("the name  is %s\n", ptr->name);
    printf("\n -------");
    print("\n");
    ptr++;
  }
  return 0;
}*/
