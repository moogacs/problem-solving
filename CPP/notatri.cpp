/*
SPOJ - NOT A TRANGLE

TAG - BINARY SEARCH

You have N (3 ≤ N ≤ 2,000) wooden sticks, which are labeled from 1 to N. The i-th stick has a length of Li (1 ≤ Li ≤ 1,000,000).
Your friend has challenged you to a simple game: you will pick three sticks at random, and if your friend can form a triangle with them (degenerate triangles included), he wins; otherwise, you win.
You are not sure if your friend is trying to trick you, so you would like to determine your chances of winning by computing the number of ways you could choose three sticks (regardless of order) such that it is impossible to form a triangle with them.
Input
The input file consists of multiple test cases. Each test case starts with the single integer N, followed by a line with the integers L1, ..., LN. The input is terminated with N = 0, which should not be processed.
Output
For each test case, output a single line containing the number of triples.
*/
#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
    int n,i,p;
    cin>>n;
    while(n)
    {   int c=0,j,p,num;
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        for(i=n-1;i>=2;i--)
        {
            num=a[i];
            for(j=i-1;j>=0;j--)
            {   p=num-a[j];
                int beg=0,last=j-1,mid,flag=0;
                while(beg<=last)
                    {
                        mid=(beg+last)/2;
                        if(p==a[mid]&&a[mid]!=a[mid-1])
                            {
                                flag=1;break;
                            }
                        else if(p>a[mid])
                            beg=mid+1;
                        else
                            last =mid-1;

                    }
                    if(flag==1)
                        c+=mid;
                    else
                        c+=beg;

            }

        }
        cout<<c<<"\n";

        cin>>n;
    }
    return 0;
}
