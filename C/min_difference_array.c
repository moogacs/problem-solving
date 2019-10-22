/* A program to find the minimum absolute difference between
 * two element of an array
 */

/* I/O
5              (this is the number of element in array)
1 4 9 22 33    (array elements)
3              (outputs 3 since 4-1=3 is the minimum absolute difference)
*/


#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void heapify(int [], int, int);
void heapSort(int [], int);

int minimumAbsoluteDifference(int n, int arr_size, int* arr) 
{
    int i, min_diff, diff;
	
	heapSort(arr, n);
	min_diff = arr[1]-arr[0];

	for(i=1;i<n;i++)
	{
		diff = arr[i]-arr[i-1];
		if(diff<min_diff)
				min_diff=diff;
	}

	return min_diff;
}

int main() 
{
    int n; 
    scanf("%i", &n);
    int *arr = malloc(sizeof(int) * n);

    for (int arr_i = 0; arr_i < n; arr_i++) 
	{
       scanf("%i",&arr[arr_i]);
    }

    int result = minimumAbsoluteDifference(n, n, arr);
    printf("%d\n", result);
    return 0;
}


void heapify(int arr[], int n, int i)
{
	int temp;
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
	int temp, i;
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
