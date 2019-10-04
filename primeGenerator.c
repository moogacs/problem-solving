#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define true 1 
#define false 0

/*
 * Program to generate prime numbers using Sieve Of Eratosthenes.
 * Input: m n.
 * Output: all the prime numbers between m and n.
 * For reference: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 */

void SieveOfEratosthenes(unsigned long long m ,unsigned long long  n){
    char *prime = (char*)malloc(sizeof(char) * (n+1));
    if(!prime){
        printf("FAIL\n");
        return;
    }
    memset(prime,true,sizeof(char)*(n+1));
    unsigned long long i = 2;
    for(i=2; i*i <= n; i++){
        if(prime[i] == true){
            for(unsigned long long j=i*i; j<=n; j+=i)
                prime[j] = false;
        }
    }
    for(i = m; i<=n; i++)
        if(prime[i] && i != 1)
            printf("%llu,", i);
}

int main() {
    clock_t begin,end;
    unsigned long long  m,n;
    scanf("%llu %llu", &m, &n);
    begin = clock();
    SieveOfEratosthenes(m,n);
    end = clock();
    double time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nTime Taken : %lf secs\n",time_spent);
    return 0;
}
