#include <bits/stdc++.h>
using namespace std;
typedef string bignum;
void  tru(bignum a, bignum b)
{
	int x;
	bignum c="";
	while (a.size()>b.size())
	b="0"+b;
	while (a.size()<b.size())
	a="0"+a;
	if (a.size()==b.size())
	{
		int num=0;
		for(int i=a.size();i>=0;i--)
		{
		x=(a[i]-48)-((b[i]-48)+num);
		num=0;
		if (x<0)
		{
			x=((a[i]-48)+10)-((b[i]-48)+num);
			num++;
		}
	c=(char)(x+48)+c;
	}
	}
	c.erase(a.size(),1);
	while (c.substr(0,1)=="0")
	c.erase(a.size(),1);
	
	cout<<"day la:"<<c;
}
int main()
{
	bignum a,b;
	cout<<"a: ";
	cin>>a;
	cout<<endl<<"b: ";
	cin>>b;
	cout<<endl;
	tru(a,b);
	return 0;
}

