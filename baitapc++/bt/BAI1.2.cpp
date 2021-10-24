#include <bits/stdc++.h>
using namespace std;
int n;
int a[10000],a1[10000],a2[10000];
void doc()
{
	cout<<"So phan tu cua day: ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
}
void xuli()
{
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i]>a[j])
			swap(a[i],a[j]);
	int k=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]%5==0)
			cout<<a[i]<<" ";
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]%7==0)
			cout<<a[i]<<" ";
	}
}
int main()
{
	doc();
	xuli();
}

