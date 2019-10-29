/*
Input the sudoku where first input denotes the no of test cases.
Then input a 2d 9X9 array , where 0 denotes an empty space.
*/
#include<bits/stdc++.h>
using namespace std;
bool canplace(int mat[][9],int i,int j,int n,int number)
{
	//  checking in row and column;
	for(int x=0;x<n;x++)
	{
		if(mat[x][j]==number || mat[i][x]==number)
		{
			return false;
		}
	}

	// checking in that particular block
	int k=sqrt(n);
	int RowStart= (i/k)*k;
	int ColStart=(j/k)*k;

	for(int p = RowStart ; p < (RowStart+k) ; p++)
	{
		for(int q = ColStart ; q < (ColStart+k) ; q++)
		{
			if(mat[p][q]==number)
			{
				return false;
			}
		}
	}
	return true;
}
void print(int mat[][9],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool sudokusolver(int mat[][9],int n,int i,int j)
{
	if(i==n)
	{
		print(mat,n);
		cout<<endl;
		return true;
	}
	// conditions
	if(j==n)
	{
		return sudokusolver(mat,n,i+1,0);
	}
	if(mat[i][j]!=0)
	{
		return sudokusolver(mat,n,i,j+1);
	}
	// recursive case
	for(int number=1;number<=n;number++)
	{
		if(canplace(mat,i,j,n,number))
		{
			// assume
			mat[i][j]=number;
			bool couldwesolve=sudokusolver(mat,n,i,j+1);
			if(couldwesolve==true)
			{
				return true;
			}
		}
	}

	// backtrack here
	mat[i][j]=0;
	return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n=9;
	int mat[9][9];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
		}
	}
	cout<<endl;
	sudokusolver(mat,n,0,0);
	cout<<endl;
	}
	return 0;
}
