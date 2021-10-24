#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int maxx=0;
int n,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]>maxx)
				maxx=a[i][j];
		}
		cout<<maxx<<endl;
		maxx=0;
	}
	return 0;
}
