//Recursive method to  find sum of digits of a number
#include<stdio.h>
int rsod(int);
void main()
{
 int num,sum;

 printf("Enter a number to find sum of its digits:");
 scanf("%d",&num);

 sum=rsod(num);//Calling rsod()

 printf("\nSum of its Digits: %d ",sum);
 }

int rsod(int num)
{
 int s=num%10;

 if(!num)
 return 0;

 s+=rsod(num/10);//Calling rsod() in rsod()
 return(s);
}
 

