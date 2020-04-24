/* Sin x is a series function and can be expanded upto infinite terms.
 Given code is used to find the value Sin x upto the desired limit, using the Taylor's series expansion
 Input: X, and number of terms that need to be calculated
 Output: value of Sin x upto the given limit
 Example: Input : X=31 deg, terms =3, Output : 0.484*/
 
#include<stdio.h>

int factorial(int fj);
float power(float fx, int fj);

int main()
{
	float x,x1,sum=0.0f;
	int i,lim,j;

	printf("\n\t Sin X series: ");
    printf("\n\t Enter X (deg): ")
	scanf("%f",&x);

	printf("Enter the limit upto which you want to expand the series: ");
	scanf("%d",&lim);
    x1=x;
	x = x*(3.1415/180);

	for(i=1;i<=limit;i++)
	{
        j=2*i-1;
		if(i%2!=0)
		{
			sum=sum+power(x,j)/factorial(j);
		}
		else
			sum=sum-power(x,j)/factorial(j);
	}

	printf("Sin(%0.1f) = %f",x1,sum);
	return 0;
}
int factorial(int fj)
{
	int i,fac = 1 ;
	for(i = 1 ; i <= fj ; i++)
		{
            fac = fac * i ;
        }
	return fac;
}
float power(float fx, int fj)
{
    float pow = 1.0;
    int i=0;
    for(i=0;i<fj;i++)
    {
        pow = fx * pow ;
    }
    return pow ;
}
