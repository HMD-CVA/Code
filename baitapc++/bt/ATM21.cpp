#include <bits/stdc++.h>
using namespace std;
int n,k,sum=0,c=0;
int dem[1000];
struct tien
{
	int prz;
	int s;
};
tien a[1000];
void doc()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		cin>>a[i].prz>>a[i].s;
}
void greedy()
{
	for(int i=1;i<=k;i++)
		for(int j=i+1;j<=k;j++)
			if(a[i].prz<a[j].prz)
				swap(a[i],a[j]);
	int r=1;
	while(n!=0)
	{
		for(int i=1;i<=a[r].s;i++)
		{
			n=n-a[r].prz;
			dem[r]++;
			if(n==0 && r==1)
			{
				cout<<dem[r]<<endl;
				cout<<a[r].prz<<" "<<dem[r];
				exit(0);
			}
			if(n<0)
			{
				n=n+a[r].prz;
				dem[r]--;
			}
		}
		r++;
	}
	if(n==0)
	{
		for(int i=1;i<=k;i++)
			sum=sum+dem[i];
		cout<<sum<<endl;
		for(int i=1;i<=k;i++)
			cout<<a[i].prz<<" "<<dem[i]<<endl;
	}
	else
		cout<<"0";
}
int main()
{
	doc();
	for(int i=1;i<=k;i++)
		c=c+(a[i].prz*a[i].s);
	if(c>=n)
		greedy();
	else
		cout<<"0";
}

