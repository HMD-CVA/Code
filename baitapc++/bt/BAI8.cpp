#include <bits/stdc++.h>
using namespace std;
int a[1000];
void nhap()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
}
int demptchan(int a[])
{
	int n=sizeof(a);
	int dem=0;
	for(int i=1;i<=n;i++)
	{
		if (a[i]%2==0)
		dem++;
	}
	return dem;
}
int main()
{
	freopen("BAI8.INP","r",stdin);
    freopen("BAI8.OUT","w",stdout);
	nhap();
	cout<<demptchan(a);
	return 0;
}

