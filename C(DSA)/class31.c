//Binary trees by array

#include<stdio.h>
char tree[10]; // global array // common for all the functions

void root(char key)
{
    if(tree[0]!='\0')
    {
        printf("Tree already has a root\n");
    }
    else
    {
        tree[0] = key;
    }
}

void set_left(char key,int parent)
{
    if(tree[parent] == '\0')
    {
        printf("\ncannot set child");
    }
    else
    {
        tree[(parent*2)+1] = key;
    }
}

void set_right(char key,int parent)
{
    if(tree[parent] == '\0')
    {
        printf("\ncannot set child");
    }
    else
    {
        tree[(parent*2)+2] = key;
    }
}

void print_tree()
{
    for(int i=0;i<10;i++)
    {
        if(tree[i]!='\0')
        {
            printf("%c",tree[i]);
        }
        else
        {
            printf("_");
        }
    }
}

int main()
{
    root('A');
    set_left('B',0); // (data,index_parent)
    set_right('C',0);
    set_left('D',1); 
    set_right('E',1);
    set_right('F',2);
    print_tree();

}