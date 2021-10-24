#include <bits/stdc++.h>
using namespace std;
typedef string bignum;
void nhan(bignum a, long b)
{
	bignum c="";
	int x,carry=0,i;
	for (i=a.size()-1;i>=0;i--)
	{
		x=(a[i]-48)*b+carry;
		carry=x/10;
		c=(char)(x%10+48)+c;
	}
	if(carry!=0)
	cout<<"a*b="<<carry<<c;
	else
	cout<<"a*b="<<c;
}
int main()
{
	bignum a,c="";
	int x,carry=0; long b;
	cout<<"a=";cin>>a;cout<<endl;
cout<<"b=";cin>>b;cout<<endl;
nhan(a,b);
return 0;
}	

