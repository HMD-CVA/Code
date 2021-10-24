#include <bits/stdc++.h>
using namespace std;
bool snt(int a)
{
	int i,dem=1;
	if (a==2)
		return true;
		else
	if (a<2)
		return false;
		else
	for (i=2;i<=a/2;i++)
	{
		if (a%i==0)
			dem++;
	}
	if (dem==1)
		return true;
		else 
			return false;
}
int xuli(int p)
{
	int a[200];
	int k=0;
	for(int i=2;i<=500000;i++)
	{
		if(snt(i))
		{
			a[k]=i;
			k++;
		}
	}
	int s=0,m;
	for(int i=0;i<k;i++)
	{
		m=a[i];
		if(p%m==0)
			s=s+m;
	}
	return s;	
}
int main()
{
	int n;
	cout<<"Nhap so tu nhien n: "; cin>>n;
	cout<<xuli(n);
	return 0;
}
