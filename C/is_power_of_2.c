#include <stdio.h>
/*
	The fastest method to spot if a number N is a power of 2 is by doing: N & (N-1)
	If the result is 0 then N is a power of two
*/
int isPowerOfTwo(int);
int main(){
	int N;
	do{
		printf("Please, insert an integer:\n");
		scanf("%d",&N);
	}while(!(N>0));
	if(isPowerOfTwo(N)==0){
		printf("\n%d is a power of two\n", N);
	}
	else printf("\n%d is NOT a power of two\n", N);
	return 0;
}
int isPowerOfTwo(int N){
	return (N & (N-1));
}
