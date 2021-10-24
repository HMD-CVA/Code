#include <bits/stdc++.h>
using namespace std;
struct bangnhac
{
	int name;
	int time;
};
int p[1000];
bangnhac a[1000];
int n,s=0;
void doc()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i].name=i;
		cin>>a[i].time;
	}
}
void xuli()
{
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		if(a[i].time>a[j].time)
		swap(a[i],a[j]);
	for(int i=1;i<=n;i++)
	{
		cout<<a[i].name<<" ";
		p[i]=p[i]+p[i-1]+a[i].time;
		cout<<p[i]<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		s=s+p[i];
	}
	cout<<s;
}
int main()
{
	doc();
	xuli();
}
