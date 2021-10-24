#include <bits/stdc++.h>
using namespace std;
int n,m,dem=0;;
int x[1000];
void doc()
{
	cin>>n>>m;
}
void ghi()
{
	int s=0;
	for(int i=1;i<=m;i++)
		s=s+x[i];
	if(s==n)
		dem++;
	s=0;
}
void bt(int i)
{
	for(int j=x[i-1]+1;j<=9-m+i;j++)
	{
		x[i]=j;
		if(i==m)
			ghi();
		else
			bt(i+1);
	}
}
void bt2(int i)
{
	for(int j=x[i-1]+1;j<=9-m+i;j++)
	{
		x[i]=j;
		if(i==m)
		{
			int s=0;
			for(int i=1;i<=m;i++)
				s=s+x[i];
			if(s==n)
			{
				for(int i=1;i<=m;i++)
					cout<<x[i];
				cout<<endl;
			}
		}
		else
			bt2(i+1);
	}
}
int main()
{
	freopen("CHIAKEO1.inp","r",stdin);
	freopen("CHIAKEO1.out","w",stdout);
	doc();
	bt(1);
	cout<<dem<<endl;
	bt2(1);
}

