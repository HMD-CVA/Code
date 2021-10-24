#include <bits/stdc++.h>
using namespace std;
char a[10000],as[10000];
int n,r;
void doc()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
}
void xuli()
{
	r=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=48;j<=57;j++)
		{
			if(static_cast<int>(a[i])==j)
			{
				as[r]=a[i];
				r++;
				for(int k=i;k<n;k++)
					a[k]=a[k+1];
				n--;
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]>a[j])
				swap(a[i],a[j]);
			if(as[i]<as[j])
				swap(as[i],as[j]);
		}
	for(int i=1;i<r;i++)
		cout<<as[i]<<" ";
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
}
int main()
{
	doc();
	xuli();
}
