#Reverse the order of the bits in a given integer.
#
#Example
#
#For a = 97, the output should be mirrorBits(a) = 67.
#
#97 equals to 1100001 in binary, which is 1000011 after mirroring, and that is 67 in base 10.
#
#For a = 8, the output should be mirrorBits(a) = 1.
#

#include <stdio.h>

int mirrorBits(int a) {
    int s = 0;

    while (a > 0) {
        s = (s << 1) | (a & 1);
        a >>= 1;
    }
    
    return s;
}

int main() {
    int a = 0;
    printf("Enter a number\n");
    scanf("%d", &a);

    printf("%d", mirrorBits(a));
    return 0;
}
