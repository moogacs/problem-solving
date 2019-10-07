//Russian Peasant Multiplication Algorithm
//
//An implementation of the russian peasant algorithm to multiply two numbers.
//The program takes two numbers as input and uses multiplication and division by
//2 to calculate their product.
//It is a faster way to calculate integer products than repeated addition.
//
//Example:
//	Input : 3 4
//	Output : 12 

#include<stdio.h>
long long int multiply(long long int, long long int);

long long int multiply(long long int a,long long int b){
	long long int res = 0;
	while(b>0){
		if(b%2 == 1) res += a;
		b = b/2; a = a*2;
	}
	return(res);
}

int main(){
	long long int a,b,c;
	printf("enter 2 numbers:\n");
	scanf("%lld %lld", &a, &b);
	c = multiply(a,b);
	printf("Answer:%lld\n", c);
	return 0;
}
