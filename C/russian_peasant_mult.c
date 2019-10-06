//Implementation of the Russian Peasant Multiplication Algorithm

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
