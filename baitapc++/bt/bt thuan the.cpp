#include <bits/stdc++.h>
using namespace std;
typedef string bignum;
int cmp(char a, char b)
{
	if (a>b)
		return 1;
	if (a==b)
		return 0;
		else return -1;
}
bignum thuanthe(bignum a)
{
	bignum b,k;
	int dem=0,i,j;
	int n=a.size();
	for(i=1;i<n;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if (cmp(a[j],a[i])==-1)
				dem++;
		}
		k=(char)(dem+48);
		b=b+k;
		dem=0;
	}
	return b;
}
int main()
{
	bignum a;
	cout<<"Nhap xau chu so a: "; cin>>a;
	cout<<"Thuan the cua a la: "<<thuanthe(a);
	return 0;
}

