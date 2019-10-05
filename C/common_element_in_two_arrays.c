/*
It is a simple comparison algorithm where the elements of 2 arrays of equal length are compared by means of simple iteration.
The final output will be the same elements in both arrays.
Considerations: No entry checks are made. 
Although the data is integer, there is no verification to verify that the data entry is valid.
Array dimension: 3
Input Array 1: 1, 3, 4
Input Array 2: 1, 5, 8
Output: 1

Español: 
Es un algoritmo de comparación simple donde los elementos de 2 arrays de igual longitud son comparados por medio de iteración simple. 
La salida final serán los elementos iguales en ambos arrays.

Consideraciones: No se hace verificaciones de entrada. 
A pesar de que los datos son enteros no se hace una verificación para comprobar que la entrada de datos sea valida.
Dimensión de los arrays: 3
Input Array 1: 1, 3, 4
Input Array 2: 1, 5, 8
Output: 1
*/

#include<stdio.h>
int main()
{
    int i,j,n;
    printf("enter the number of elements in an arrays\n");
    scanf("%d",&n);
    int a[n],b[n];
    printf("enter the elements of 1st array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the elements of 2nd array\n");
    for(j=0;j<n;j++)
    {
        scanf("%d",&b[j]);
    }
    printf("The common numbers are: ");
   for(i=0; i<n; i++){
	   for(j=0;j<n;j++){
		   if(a[i]==b[j]){
			   printf("%d\n", b[j]);
			   }
		   }
    }
}
