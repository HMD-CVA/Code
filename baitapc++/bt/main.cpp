#include <bits/stdc++.h>
using namespace std;
typedef string bignum;
void dev(bignum a, bignum b)
{
	bignum c="";
	int x,i;
	while (a.size()<b.size()); a="0"+a;
	while (a.size()>b.size()); b="0"+b;
	int bor=0;
	for (i=a.size()-1;i>=0;i--)
	{

		x=(a[i]-48)-((b[i]-48)+bor);
		bor=0;
		if (x<0)
        {
        x=((a[i]-48)+10)-((b[i]-48)+bor);
		bor++;
        }
		c=(char)(x+48)+c;
	}
	cout<<"dev "<<c;
}
int main()
{
	bignum a,b;
	cout<<"a= "; cin>>a; cout<<endl;
	cout<<"b= "; cin>>b; cout<<endl;
	dev(a,b);
	return 0;
}


