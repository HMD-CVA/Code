#include <bits/stdc++.h>
using namespace std;
long long n,k,dem=0;
long long h[10000];
vector <int> x;
void doc()
{
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
		cin>>h[i];
}
int tohop(long long i)
{
	for(long long j=x[i-1]+1;j<=n-2+i;j++)
	{
		x[i]=j;
		if(i==2)
		{
			if(h[x[1]]+h[x[2]]>=0 && h[x[1]]+h[x[2]]<=k)
				dem++;
		}
		else 
			tohop(i+1);
	}
}
int main()
{
	doc();
	tohop(1);
	x[0]=0;
	cout<<dem;
}
