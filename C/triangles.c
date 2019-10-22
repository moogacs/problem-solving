/*This program receives two integers m and n indicating respectively the number of rows 
and the number of columns in the matrix to be inserted.

Immediately after that, it receives a binary matrix, that is, a matrix formed only with 
zeros (0) or ones (1), which has dimension m x n.

The output will be an integer p, which indicates the amount of '1' forming the largest 
triangle present in the binary matrix.

Sample Input:
5 7
0 0 0 1 0 0 0
0 0 1 1 1 0 0
0 1 1 1 1 1 0
1 1 1 1 1 1 1
1 1 1 1 1 1 1

Sample Output:
16
*/
#include <stdio.h>
#include <string.h>
#define max(a,b) a>b?a:b

int main(){
    int altura, largura, mat[1000][1000], i, j, k, inicio, flag, c, final, tam, soma, resp=0;
    scanf("%d %d", &altura, &largura);
    for(i=0;i<altura;i++){
        for(j=0;j<largura;j++){
            scanf("%d", &mat[i][j]);
        }
    }
    for(i=0;i<altura;i++){
        for(j=0;j<largura;j++){
            if(mat[i][j]==1){
                tam=1;
                soma=1;
                flag=1;
                inicio = j-1;
                final = j+1;
                for(k=i+1;k<altura && flag==1;k++){
                    if(inicio>=0 && final<largura){
                        for(c=inicio;c<=final;c++){
                            if(mat[k][c]==0){
                                flag=0;
                            }
                        }
                        if(flag==1){
                            soma+=2;
                            tam+=soma;
                        }
                        inicio--;
                        final++;
                    }
                }
                resp = max(tam,resp);
            }
        }
    }
    
    printf("%d",resp);
    return 0;
}
