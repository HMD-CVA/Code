#include <bits/stdc++.h>
using namespace std;
int n,m=1;
int k;
int a[1000],x[1000],d[1000],ch[99999];
void doc()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
}
int cl()
{
	int s=0,s1=0;
	for(int r=1;r<=k;r++)
		s=s+x[r];
	for(int r=1;r<=n;r++)
	{
		for(int z=1;z<=k;z++)
		{
			if(a[r]==x[z])
				a[r]=0;
		}
	}
	for(int i=1;i<=n;i++)
		s1=s1+a[i];
	int l=fabs(s-s1);
	s=0;
	s1=0;
	return l;
	
}
void bt(int i,int k)
{
	for(int j=1;j<=n;j++)
	{
		if(d[j]==0)
		{
			x[i]=a[j];
			d[j]=1;
			if(i==k)
			{
				ch[m]=cl();
			}
			else
			{
				bt(i+1,k);
				d[j]=0;
			}
	    }	
	}
}
void kq()
{
	int arrmin=ch[1];
	for(int i=2;i<=n;i++)
	{
		if(arrmin>ch[i])
			arrmin=ch[i];
	}
	cout<<arrmin;
}
int main()
{
	freopen("CHIAKEO2.inp","r",stdin);
	freopen("CHIAKEO2.out","w",stdout);
	doc();
	for(k=1;k<n;k++)
		bt(1,k);
	kq();	
}

