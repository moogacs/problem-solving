#include<stdio.h>
#include<stdlib.h>

void main()
{
    int *arr, size, element, flag = 0, i;

    printf("Enter the size of array:");
    scanf("%d", &size);

    arr = (int*)malloc(size * sizeof(int));

    printf("Enter values accordingly:\n");
    
    for(int i = 0; i<size; i++)
        scanf("%d", (arr+i));

    printf("Enter the Element to be searched:");
    scanf("%d", &element);

    for(i = 0; i<size; i++)
        if(arr[i] == element)
        {
            flag = 1;
            break;
        }

    flag?printf("Element found at %dth index", i) : printf("Element Not Found");

}