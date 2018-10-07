#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

int validate(char k[MAX])
{
    for (int i = 0; k[i] != '\0'; i++)
    {
        if (!isalpha(k[i]))
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char* argv[])
{
    if (argc != 2 || validate(argv[1]))
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    int k_len = strlen(argv[1]);
    for (int i = 0; i < k_len; i++)
    {
        char type = isupper(argv[1][i]) ? 'A' : 'a';
        argv[1][i] -= type;
    }
    char p[MAX];
    printf("plaintext: ");
    fgets(p, sizeof(p), stdin);
    printf("ciphertext: ");
    for (int i = 0, j = 0, k = strlen(p), m; i < k; i++)
    {
        if (!isalpha(p[i]))
        {
            printf("%c", p[i]);
            continue;
        }
        m = j++ % k_len;
        char type = isupper(p[i]) ? 'A' : 'a';
        printf("%c", (((p[i] - type) + argv[1][m]) % 26) + type);
    }
    printf("\n");
    return 0;
}
