#include<stdio.h>
int main()
{
        int a,b,mod,result=1;
        scanf("%d %d %d",&a,&b,&mod);
        int bit=8*sizeof(b);

        for(int i=0;i<bit;i++)
        {
                printf("%d\n",b);
                if(1&b)
                {
                        result=(a*result)%mod;
                }
                a=(a*a)%mod;
                b>>=1;

                printf("%d:no. of iletrations\n",i);
                printf("result:%d\n",result);
        }
        printf("%d\n",result);
        return 0;
}

