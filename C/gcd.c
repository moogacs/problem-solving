#include <stdio.h>
#include <math.h>
int gcd(int a,int b)
{
	int hcf;
	int small=(a<b)?a:b;
	int great=(a>b)?a:b;
	if (great%small==0)
		return small;
	for (int i=1;i<=(small/2);i++)
	{
		if (a%i==0 && b%i==0)
			hcf=i;
	}
	return hcf;
}
int main(void)
{
	printf("enter two positive numbers: ");
	int a,b;
	scanf("%d %d",&a,&b);
	printf("gcd of %d and %d is %d",a,b,gcd(a,b));
}
