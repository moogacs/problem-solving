/* Custom Fibonacci sequence
 * In input, you'll receive two numbers:
    - the first one is the starting number (in the Fibonacci series)
    - the second one is the n numbers to calculate after value1

 * Example:
    - input: 34 7
    - output: 55,89,144,233,377,610,987
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// fibonacci series calculator function
int fib(int n)
{
    int a = 0;
    int b = 1;
    while (n-- > 1) {
        int t = a;
        a = b;
        b += t;
    }
    return b;
}

int main(int argc, char **argv) {
    int value1 = atoi(argv[1]);
    int value2 = atoi(argv[2]);
    int index = 1, fibo = 1;

    // calculate the starting number index in Fibonacci series
    for(int i = 0; fibo < value1; i = fibo - i){
        fibo += i;
        index++;
    }
    
    // calculate the n numbers after value1
    for(int i = 0; i < value2; i++){
        if(i == value2 - 1){
            index++;
            printf("%d", fib(index));
        } else {
            index++;
            printf("%d,", fib(index));
        }
    }
}
