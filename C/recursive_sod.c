//Recursive method to  find sum of digits of a number
//Prints a sum of digits of a number. For example
//For Input num=123 
//Output Sum of its digits=6
//Similarly for Input=111 Output=3
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
 

