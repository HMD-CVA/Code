#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int s,dem1=0,dem2=0,p;
void doc()
{
	cin>>a>>b>>c;
}
int xuli(int a,int b,int c)
{
	s=0;
	while(s<c)
	{
		s=s+min(a,b);
		dem1++;
	}
	s=s-min(a,b);
	dem1--;
	while((c-s)%(max(a,b))!=0)
	{
		s=s-min(a,b);
		dem1--;
		if(s<=0)
			return -1;
	}
	dem2=(c-s)/max(a,b);
	int k=dem1+dem2;
	return k;
}
int main()
{
	freopen("COINS.INP","r",stdin);
	freopen("COINS.OUT","w",stdout);
	doc();
	cout<<xuli(a,b,c);
}

