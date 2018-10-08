/*

is a type of substitution cipher in which each letter in the plaintext is 'shifted' a certain number of places down the alphabet.  
For example, with a shift of 1, A would be replaced by B, B would become C, and so on.  
plaintext:  defend the east wall of the castle
ciphertext: efgfoe uif fbtu xbmm pg uif dbtumf
Formula: c[i] = (p[i] + key) % 26;
c: ciphertext
p: plaintext

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    
    if(argc != 2) {
        printf("Usage is ./caesar k\n");
        return -1;
    }

    // get the number of places to rotate 
    int k = atoi(argv[1]);

    // get the string to encode
    printf("Enter the string to encode.\n");
    char str[100];
    fgets(str, sizeof(str), stdin);

    // iterate through array one char at a time
    for(int i = 0; str[i] != '\0'; i++) {

        // encoding is only valid on alphabets
        if(!isalpha(str[i])) {
            printf(str[i]);
            continue;
        }

        // find out if its uppercase or lowercase
        int type = isupper(p[i]) ? 'A' : 'a';

        // we subtract type to get a number between 0 to 26
        // then add the key and perform modulo to get another number in 0-26
        // and when we add type again, it becomes a valid alphabet character 
        printf("%c", (((p[i] - type) + k) % 26) + type);
    }

    return 0;
}
