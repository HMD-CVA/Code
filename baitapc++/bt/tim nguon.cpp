#include <bits/stdc++.h>
using namespace std;
typedef string bignum;
bignum bigdiv(bignum a, bignum b)
{
	bignum c=""; int s;
	int num=0;
	while (b.size()<a.size()) b="0"+b;
	for (int i=a.size()-1;i>=0;i--)
	{
		s=(a[i]-48)-(b[i]-48)-num;
		num=0;
		if (s<0)
		{
			s=s+10;
			num++;
		}
		c=(char)(s+48)+c;
	}
	return c;
}
int cmp(bignum a, bignum b)
{
	while (a.size()<b.size()) a="0"+a;
	while (a.size()>b.size()) b="0"+b;
	if (a>b) return 1;
	if (a==b) return 0;
	else return -1;
}
int main()
{
	bignum k="",l="",m="";
	bignum tach[100];
	bignum nguon[100];
	bignum a,n,s,min;
	cout<<"M=";cin>>a;
	int b=9*(a.size());
	for(int i=1;i<=b;i++)
	{
		k=(char)(i/10+48);
		l=(char)(i%10+48);
		m=k+l;
		n=bigdiv(a,m);
		for(i=0;i<n.size();i++)
			tach[i]=n.substr(i,1);
		s=n;
		for(i=0;i<n.size();i++)
		{
			s=s+tach[i];
		}
		if(cmp(s,a)==0)
		nguon[i-1]=s;
	}
	if(sizeof(nguon)>1)
	{
	min=nguon[0];
	for(int j=1;j<sizeof(nguon);j++)
	{
		if (cmp(nguon[j],min)==-1)
			min=nguon[j];
	}
	cout<<"Nguon nho nhat cua M la: "<<min;
	}
	if(sizeof(nguon)==1)
	cout<<"Nguon nho nhat cua M la: "<<nguon[0];
	else
		cout<<"0";
	return 0;	
}

