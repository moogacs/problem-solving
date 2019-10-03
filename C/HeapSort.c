#include <stdlib.h>
#include <stdio.h>
#define MAX 300


int main(void) {
  int n, V[MAX];
  n = leggi_array(V);
  HeapSort(V, n);
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

//inserisce l'elemento x nell'heap H.
void Inserisci(int x, int H[]) {
  int l;
  l = H[0]+1;
  H[0] = H[0]+1;
  H[l] = x;
  while (l>1 && H[l/2]<H[l]) {
    scambia(&H[l], &H[l/2]);
    l = l/2;
  }
  return;
}

/*
 *  restituisce il massimo elemento
 *  dell'heap H (la radice) e ricostruisce la
 *  struttura di heap.
 */

int EstraiMax(int H[]) {
  int max, i;
  max = H[1];
  H[1] = H[H[0]];
  H[0] = H[0]-1;
  i = 1;
  while (2*i<H[0] && (H[i]<H[2*i] || H[i]<H[2*i+1])) {
    if (H[2*i] > H[2*i+1]) {
      scambia(&H[i], &H[2*i]);
      i = 2*i;
    } else {
      scambia(&H[i], &H[2*i+1]);
      i = 2*i+1;
    }
  }
  if (2*i == H[0] && H[i] < H[2*i])
    scambia(&H[i], &H[2*i]);
  return(max);
}

/*
 *  ordina l'array A mediante l'algoritmo Heap Sort.
 */

void HeapSort(int A[], int n) {
  int i, H[MAX];
  H[0] = 0;
  for (i=0; i<n; i++)
    Inserisci(A[i], H);
  for (i=n-1; i>=0; i--)
    A[i] = EstraiMax(H);
  return;
}
