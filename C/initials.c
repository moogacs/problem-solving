/*

    Given a name in a string, display its initials.
    INPUT : "Welcome To Apple"
    OUTPUT : "WTA"

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int main (void)
{
    char name[MAX];
    fgets(name, sizeof(name), stdin);
    
    printf("%c", toupper(name[0]));
    
    for (int i = 1; name[i] != '\0'; i++)
    {
        if (name[i] == ' ')
        {
            printf("%c", toupper(name[i + 1]));
        }
    }
    
    printf("\n");
}