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

//scambia il valore delle due variabili.
void scambia(int *x, int *y) {
    int z;
    z = *x;
    *x = *y;
    *y = z;
    return;
}

/*
 * Legge in input il numero n ed n numeri interi
 * che memorizza nell'array. Restituisce il numero
 * di elementi letti (n).
 */

int leggi_array(int V[]) {
    int n, i;
    printf("Numero di elementi: ");
    scanf("%d", &n);
    printf("Inserisci %d numeri: ", n);
    for (i=0; i<n; i++)
	scanf("%d", &V[i]);
    return(n);
}

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
