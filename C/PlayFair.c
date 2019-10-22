#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char tab[5][5], map[26], key[25];

    bzero(map, 26);

    printf("Enter a key(maximum length 25): ");
    fgets(key, 25, stdin);
    if(key[strlen(key)-1] == '\n')
	key[strlen(key)-1] = '\0';
    for(int i=0;key[i]!='\0';i++)
	key[i] = toupper(key[i]);

    for(int i=0;key[i]!='\0';i++)
 	map[key[i]%26]++;

    for(int i=0;key[i]!='\0';i++)
    {
	if(map[key[i]%26] == 2)
	    map[key[i]%26]++;
	else if(map[key[i]%26] >= 3)
	{
	    for(int j=i;key[j]!='\0';j++)
		key[i] = key[i+1];
	}
    }

    int i;
    for(i=0;key[i]!='\0';i++)
	*(*(tab)+i) = key[i];

    for(char c='A';c<='Z';c++)
    {
	if(!map[c%26])
	{
	    if(c != 'I')
	    {
		*(*(tab)+i) = c;
		i++;
	    }
	}
    }

    char plain[65], cipher[65];
    printf("Enter Plain text(maximum length 64; Enter q to quit): ");

    while(scanf("%s", plain))
    {
	if(strlen(plain) == 1 && toupper(plain[0]) == 'Q')
	    break;
	
	int clen=0;
	for(int i=0;plain[i]!='\0';i+=2)
	{

	    int x1, x2, y1, y2, flag=0;

	    char c1 = toupper(plain[i]), c2 = toupper(plain[i+1]);
			    
	    if(c1 == c2 || c2 == '\0')
	    {
		c2 = 'X';
		i--;
	    }
	    for(int j=0;j<5;j++)
	    {
		for(int k=0;k<5;k++)
		{
		    if(tab[j][k] == c1 || (c1 == 'I' && tab[j][k] == 'J'))
		    {
			x1 = k;
			y1 = j;
			flag++;
		    }
		    if(tab[j][k] == c2 || (c2 == 'I' && tab[j][k] == 'J'))
		    {
			x2 = k;
			y2 = j;
			flag++;
		    }
		    if(flag==2)
			break;
		}
		if(flag==2)
		    break;
	    }
	    if(x1 == x2)
	    {
		cipher[clen] = tab[++y1%5][x1];
		cipher[clen+1] = tab[++y2%5][x2];
	    }
	    else if(y1 == y2)
	    {
		cipher[clen] = tab[y1][++x1%5];
		cipher[clen+1] = tab[y2][++x2%5];
	    }
	    else
	    {
		cipher[clen] = tab[y1][x2];
		cipher[clen+1] = tab[y2][x1];
	    }
	    clen += 2;
	}

	cipher[clen] = '\0';
	printf("%s ", cipher);
    }
    return 0;
}
