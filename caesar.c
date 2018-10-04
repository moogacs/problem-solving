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
