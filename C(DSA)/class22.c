//top-down and bottom -up method of heapifying an array(max heap)


#include <stdio.h>

void heapify_bottom_up(int arr[], int n)
{
    for(int i = n / 2-1; i >= 1; i--)//last leaf node at n/2-1 index
    {
        int k = i;
        int v = arr[k];
        int heap = 0;
        while(!heap && 2 * k + 1 < n)
        {
            int j = 2 * k + 1;//left child index
            if(j + 1 < n) // 2 children check
            {
                if(arr[j] < arr[j + 1])
                {
                    j = j + 1;
                }
            }
            if(v >= arr[j]) // heap check to see if parent value greater than children value
            {
                heap = 1;
            }
            else
            {
                arr[k] = arr[j];
                k = j;
            }
        }
        arr[k] = v;
    }
}

void heapify_top_down(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int k = i;
        int v = arr[k];
        int heap = 0;
        while(!heap && k > 0)
        {
            int j = (k - 1) / 2;//index of parent node
            if(v <= arr[j]) // heap check to see if parent value greater than children value
            {
                heap = 1;
            }
            else
            {
                arr[k] = arr[j];
                k = j;
            }
        }
        arr[k] = v;
    }
} 
void delete_max(int arr[], int *n)
{
    if(*n <= 0)
    {
        printf("Heap is empty\n");
        return;
    }

    int max_element = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify_bottom_up(arr, *n);

    printf("Deleted max element: %d\n", max_element);
}

void insert_element(int arr[], int *n, int element)
{
    arr[*n] = element;
    (*n)++;
    heapify_top_down(arr, *n);
}

int main()
{
    int n;
    while(1)
    {
        printf("Enter the number of elements: ");
        scanf("%d",&n);
        int arr[n+1]; // +1 to accommodate new element in insert
        printf("Enter the elements: ");
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        heapify_bottom_up(arr,n);
        printf("Heapified array (Bottom-Up): ");
        for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
        int choice, element;
        while(1) {
            printf("1. Insert element\n2. Delete max element\n3. Display heap\n4. Exit\nEnter your choice: ");
            scanf("%d", &choice);
            switch(choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insert_element(arr, &n, element);
                break;
            case 2:
                delete_max(arr, &n);
                break;
            case 3:
                printf("Heap: ");
                for(int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
            }
        }
    
    return 0;
    }
}  

