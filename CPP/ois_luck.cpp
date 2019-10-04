/*
You are given K, C, and K distinct 4-digit integers L
Find the integer with C digits that contains the highest amount of numbers in L
source: https://training.olinfo.it/#/task/ois_luck/statement
*/

#pragma GCC optimize("Ofast")

#include <stdio.h>
#include <vector>

using namespace std;

const int MK = 202;
const int MC = 10004;

int k,c,n,tmp,res,i,mi;
bool b;
vector< pair<int,int> > g[MK];
bool lucky[10000];
int a[MK];
int f[MC][MK];
int d[MK][2];

inline int dist(int a, int b){
	if(a%1000==b/10)return 1;
	if(a%100==b/100)return 2;
	if(a%10==b/1000)return 3;
	return 4;
}
//fastio
char buff[20];
inline void printint(int n){
	int ind=1;
	for(;n;n/=10)buff[ind++]=n%10;
	for(ind--;ind;--ind)putchar_unlocked(buff[ind]+'0');
}
char ch;
inline void scanint(int & n){
	n=0;
	while((ch=getchar_unlocked())>='0'&&ch<='9')n=n*10+ch-'0';
}

/*
In short the solution consists of building a graph
where the nodes are the 4-digit numbers and an edge bethween
two nodes has weight equal to the number of new digits that you
need to add to the number to get the second number
(eg 1234->4567 has weight 3 because the 4 is in common)
then we need to find the "shortest" path that builds a number with C digits
*/

int main(){
	scanint(k);
	scanint(c);
	for(i=0; i<k; ++i){
		tmp=(getchar_unlocked()-'0')*1000+(getchar_unlocked()-'0')*100+(getchar_unlocked()-'0')*10+(getchar_unlocked()-'0');
		getchar_unlocked();
		if(!lucky[tmp]){
			a[n++]=tmp;
			lucky[tmp]=1;
		}
	}
	for(i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(dist(a[i],a[j])<4)g[i].push_back({j,dist(a[i],a[j])});
		}
	}
	for(i=0; i<n; ++i){
		d[i][b]=4;
		f[0][i]=-1;
	}
	while(1) {
		for(i=0; i<n; ++i){
			d[i][!b]=d[mi][b]+4;
			f[res+1][i]=mi;
		}
		for(i=0; i<n; ++i){
			for(auto j:g[i]){
				if(d[i][b]+j.second<d[j.first][!b]){
					d[j.first][!b]=d[i][b]+j.second;
					f[res+1][j.first]=i;
				}
			}
		}
		mi=0;
		for(i=0; i<n; ++i){
			if(d[mi][!b]>d[i][!b])mi=i;
		}
		if(d[mi][!b]>c)break;
		++res;
		b=!b;
	}
	mi=0;
	for(i=0; i<n; ++i){
		if(d[i][b]<d[mi][b]){
			mi=i;
		}
	}
	vector<int> rres;
	for(;res>=0;--res){
		rres.push_back(mi);
		mi=f[res][mi];
	}
	printint(a[rres.back()]);
	c-=4;
	for(i=rres.size()-2; i>=0; --i){
		switch(dist(a[rres[i+1]],a[rres[i]])){
		case 1:
			tmp=a[rres[i]]%10;
			c--;
			break;
		case 2:
			tmp=a[rres[i]]%100;
			c-=2;
			break;
		case 3:
			tmp=a[rres[i]]%1000;
			c-=3;
			break;
		default:
			c-=4;
			tmp=a[rres[i]];
		}
		printint(tmp);
	}
	while(c--)putchar_unlocked('0');
	return 0;
}
