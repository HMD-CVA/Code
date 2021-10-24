#include <bits/stdc++.h>
using namespace std;
int m,n,dem=0;
bool prime(int a)
{
	if(a==2)
		return true;
	else
	{
		for(int i=2;i<=sqrt(a);i++)
			if(a%i==0)
				return false;
		return true;
	}
}
bool symmetrical(int a)
{
	int i=a;
	int sum=0;
	while(i!=0)
	{
		int r=i%10;
		i=i/10;
		sum=sum*10+r;
	}
	if(sum==a)
		return true;
	else
		return false;
}
int main()
{
	cin>>m>>n;
	for(int k=m;k<=n;k++)
	{
		if(prime(k) && symmetrical(k))
		{
			cout<<k<<endl;
			dem++;
		}
	}
	if(dem==0)
		cout<<"0";
}
