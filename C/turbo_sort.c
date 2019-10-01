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
