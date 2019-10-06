   //solution to domino-piling problem on code forces 

#include <stdio.h>
#include <math.h>
     
    int main() {
    	int m,n,a,cnt;
    	scanf("%d %d",&m,&n);
    	//no. of domino tiles required will be total area divided by area of one tile (2)
	a=m*n;
    	cnt=a/2;
    	printf("%d",cnt);
      	return 0;
     }
