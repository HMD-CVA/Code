#include <bits/stdc++.h>
using namespace std;
typedef string bignum;
int cmp(bignum a, bignum b)
{
	while (a.size()<b.size()) a="0"+a;
	while (a.size()>b.size()) b="0"+b;
	if (a>b)
		return 1;
	if (a==b)
		return 0;
		else return -1;
}
bignum bigadd(bignum a, bignum b)
{
    int i,s,carry=0;
    bignum c="";
    while(a.size()<b.size()) a="0"+a;
    while(a.size()>b.size()) b="0"+b;
    for (i=a.size()-1;i>=0;i--)
    {
        s=(a[i]-48)+(b[i]-48)+carry;
        carry=0;
        if(s>=10)
        {
            carry=s/10;
            s=s%10;
        }
        c=(char)(s+48)+c;
	}
	c=(char)(carry+48)+c;
    return c;
}
int main()
{
  bignum fibo[1000]; bignum s;
  fibo[0]="0";
  fibo[1]="1";
  fibo[2]="1";
  for (int i=3;i<1000;i++)
    fibo[i]=bigadd(fibo[i-2],fibo[i-1]);
  bignum n;
  cout<<"Nhap so n: "; cin>>n; 
  int m=1; int a;
  while (cmp(fibo[m],n)==-1)
    {
        m++;
        int a=m-1;;
    }
    int z=1;bignum k;
    k=fibo[a]+k;
    while(cmp(fibo[a],n)==-1)
	{
		k=bigadd(k,fibo[z]);
		z++;
	}
	cout<<n<<"="<<fibo[a]<<"+";
	for (int j=1;j=z;j++)
		cout<<fibo[j]<<"+";
		cout<<"0";
	return 0;
}

