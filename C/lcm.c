#include <stdio.h>
int lcm(int a,int b)
{
	int lcm=a*b;
	int great=(a>b)?a:b;
	int small=(a<b)?a:b;
	if (great%small==0)
		return great;
	for (int i=great+1;i<a*b;i++)
	{
		if (i%a==0 && i%b==0)
		{
			lcm=i;
			break;
		}
	}
	return lcm;
}
int main(void)
{
	printf("enter two positive numbers: ");
	int a,b;
	scanf("%d %d",&a,&b);
	printf("LCM of %d and %d is %d",a,b,lcm(a,b));
}
