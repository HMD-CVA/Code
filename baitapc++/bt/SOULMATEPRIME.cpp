#include <bits/stdc++.h>
using namespace std;
int maxx=pow(10,5);
int a1[10001],a2[10001],n[1001];
int t;
void doc()
{
	cin>>t;
	for(int i=1;i<=t;i++)
		cin>>n[i];
}
bool prime(int x)
{
	if(x==2)
		return true;
	else
	{
		for(int i=2;i<=sqrt(x);i++)
		{
			if(x%i==0)
				return false;
		}
		return true;
	}
}
int main()
{
	doc();
	int k=2;
	a1[1]=5;
	a2[1]=11;
	for(int i=a1[k-1]+1;i<=maxx;i++)
	{
		if(prime(i) && prime(i+6))
		{
			a1[k]=i;
			a2[k]=i+6;
			k++;
		}
	}
	for(int i=1;i<=t;i++)
		cout<<a1[n[i]]<<" "<<a2[n[i]]<<endl;
}

