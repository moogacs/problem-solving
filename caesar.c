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

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    int k = atoi(argv[1]);
    char p[100];
    printf("plaintext: ");
    scanf("%s", &p);
    printf("ciphertext: ");
    for (int i = 0, type; p[i] != '\0'; i++)
    {
        if (!isalpha(p[i]))
        {
            printf("%c", p[i]);
            continue;
        }
        type = isupper(p[i]) ? 'A' : 'a';
        printf("%c", (((p[i] - type) + k) % 26) + type);
    }
    printf("\n");
    return 0;
}
