/*
Given the list of numbers, you are to sort them in non decreasing order.

Input
t – the number of numbers in list, then t lines follow [t <= 10^6].
Each line contains one integer: N [0 <= N <= 10^6]

Output
Output given numbers in non decreasing order. */


#include<stdio.h>

int arr[1000000] = {0};

int main(){

    int a,i,n;

    scanf("%d",&n);

    while(n--){
        scanf("%d",&a);
        arr[a]++;
    }
    a = 0;

    while(a<1000000){
        while(arr[a]){
            printf("%d",a);
            arr[a]--;
        }
        a++;
    }
}
