/*This program adds two large numbers.
The input is made up of 4 lines: on 1st line the number of digits of 1st number, on 
2nd line the digits of 1st number separated by space, on 3rd line the number
of digits of 2nd number, and on 4th line the digits of 2nd number separated by space.
The output is the large number resulting from the sum of the input numbers (without space between digits).
Sample Input:
30
1 2 3 4 5 6 7 8 9 1 4 2 6 7 8 9 3 2 1 5 6 7 8 2 3 5 6 5 2 1
30
9 2 4 8 1 9 4 2 6 0 2 4 7 5 1 8 3 4 2 1 4 8 9 4 5 9 2 4 0 2
Sample Output:
1048276215167430766371676948923
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int d, n1, n2, i, a1[10000]={0}, a2[10000]={0}, r[100000]={0},k=0;
    scanf("%d",&n1);
    for(i=0;i<n1;i++){
        scanf("%d",&a1[i]);
    }
    scanf("%d",&n2);
    for(i=0;i<n2;i++){
        scanf("%d",&a2[i]);
    }
    if(n1>n2){
        d = n1-n2;
        for(i=n2-1;i>=0;i--){
            a2[i+d]=a2[i];
        }
        for(i=0;i<d;i++){
            a2[i]=0;
        }
        for(i=n1-1;i>0;i--){
            r[i]=a1[i]+a2[i];
            k++;

            if(r[i]>9){
                r[i]=r[i]-10;
                a1[i-1]=a1[i-1]+1;
            }
        }
        r[0]+=a1[0]+a2[0];
    }

    if(n1<=n2){
        d = n2-n1;
        for(i=n1-1;i>=0;i--){
            a1[i+d]=a1[i];
        }
        for(i=0;i<d;i++){
            a1[i]=0;
        }
        for(i=n2-1;i>0;i--){
            r[i]=a1[i]+a2[i];
            k++;
            if(r[i]>9){
                r[i]=r[i]-10;
                a2[i-1]=a2[i-1]+1;
            }
        }
        r[0]+=a1[0]+a2[0];
    }
    for(i=0;i<=k;i++){
        printf("%d",r[i]);
    }
    

	return 0;
}
