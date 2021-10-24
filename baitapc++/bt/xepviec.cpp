#include <bits/stdc++.h>
using namespace std;
struct viec
{
	int name;
	int time;
	int prz;
};
viec a[1000];
int n,r[100],k,s=0;
void doc()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i].name=i;
		cin>>a[i].time;
		cin>>a[i].prz;
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
		k=1;
		if(a[i].time==a[i+1].time)
		{
			if(a[i].prz>a[i+1].prz)
			{
				s=s+a[i].prz;
				r[k]=a[i+1].name;
				cout<<a[i].name<<endl;
				i++;
			}
			else
			{
				s=s+a[i+1].prz;
				cout<<a[i+1].name<<endl;
				r[k]=a[i].name;
				i++;
			}
		}
		else
		{
			cout<<a[i].name<<endl;
			s=s+a[i].prz;
		}
	}
	for(int i=1;i<=k;i++)
		cout<<r[i]<<endl;
	cout<<s;
}
int main()
{
	doc();
	xuli();
}

