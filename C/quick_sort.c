/* 
 * This algorithm uses the quicksort algorithm
 * to sort an array of n elements
 * best case: O(n log n)
 * worst case: O(n^2)
 * average case: O(n log n)
 */

/* I/O
 * Numero di elementi: 5 (This is the number of elements)
 * Inserisci 5 numeri: 4 1 3 0 100
 * 0 1 3 4 100 (This is the new sorted array)
 */

#include <stdlib.h>
#include <stdio.h>
#define MAX 300

void scambia(int *, int*);
int leggi_array(int []);
void QuickSort(int [], int, int);
void stampa_array(int [], int);

int main(void) {
    int n, V[MAX];
    n = leggi_array(V);
    QuickSort(V, 0, n-1);
    stampa_array(V, n);
    return(0);
}

//Interchange numbers
void scambia(int *x, int *y) {
    int z;
    z = *x;
    *x = *y;
    *y = z;
    return;
}

//get input and number of elements
int leggi_array(int V[]) {
    int n, i;
    printf("Numero di elementi: ");
    scanf("%d", &n);
    printf("Inserisci %d numeri: ", n);
    for (i=0; i<n; i++)
	scanf("%d", &V[i]);
    return(n);
}

//print array
void stampa_array(int V[], int n) {
    int i;
    for (i=0; i<n; i++) {
	printf("%d ", V[i]);
    }
    printf("\n");
    return;
}

void QuickSort(int V[], int low, int high)
{
    int pivot = V[high];
    int t = 0;

    if(low < high)
    {
	for(int i=0;i<high;i++)
	{
	    if(V[i]<pivot)
	    {
		scambia(&V[i], &V[t]);
		t++;
	    }
	}
	scambia(&V[t], &V[high]);
	QuickSort(V, low, t-1);
	QuickSort(V, t+1, high);
    }
}
