#include <bits/stdc++.h>
using namespace std;
typedef string bignum;
bignum add(bignum a, bignum b)
{
	bignum c="";
	int i,carry=0,n;
	while(a.size()<b.size()) a="0"+a;
	while(a.size()>b.size()) b="0"+b;
	for(i=a.size()-1;i>=0;i--)
	{
		n=(a[i]-48)+(b[i]-48)+carry;
		carry=0;
		if(n>=10)
		{
			n=n%10;
			carry++;
		
		}
		c=(char)(n+48)+c;
	}
	return c;
}
bignum sub(bignum a, bignum b)
{
	bignum c="";
	int i,num=0,n;
	while(a.size()<b.size()) a="0"+a;
	while(a.size()>b.size()) b="0"+b;
	for(i=a.size()-1;i>=0;i--)
	{
		n=(a[i]-48)-(b[i]-48)-num;
		num=0;
		if (n<0)
		{
			n=n+10;
			num++;
		}
		c=(char)(n+48)+c;
	}
	return c;
}
int cmp(bignum a, bignum b)
{
	while(a.size()<b.size()) a="0"+a;
	while(a.size()>b.size()) b="0"+b;
	if (a==b)
		return 0;
	if (a>b)
		return 1;
	else
		return -1;
}
bignum bigdiv2(bignum a, bignum b)
{
	bignum c;
	bignum du; bignum s[11];
	s[0]='0';
	for(int i=1;i<11;i++)
	{
		s[i]=add(s[i-1],b);
	}
	for(int j=0; j<a.size();j++)
	{
		du=du+a[j];
		int k=1;
		while(cmp(du,s[k])!=-1)
			k++;
		c=(char)(k-1+48)+c;
		du=sub(du,s[k-1]);
	}
	return c;
}
int main()
{
	bignum a,b,c;
	cout<<"a=";cin>>a;
	cout<<"b=";cin>>b;
	c=bigdiv2(a,b);
	cout<<"a/b="<<c;
	return 0;
}


