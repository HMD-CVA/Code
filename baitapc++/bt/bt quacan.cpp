#include <bits/stdc++.h>
using namespace std;
typedef string bignum;
bignum tamphan(int n)
{
	bignum x="";
	while(n!=0)
	{
		x=(char)(n%3+48)+x;
		n=n/3;
	}
	x="0"+x;
	return x;
}
void choncan(int n)
{
	int vephai[100];
	int vetrai[100];
	int k=0,i,t;
	bignum x="";
	x=tamphan(n);
	for(i=x.size()-1;i>=0;i--)
	{
		if(x[i]=='2')
		{
			t=(int)(x[i-1]-48);
			x[i-1]=(char)(t+1+48);
			vephai[i]=k;
		}
		k++;
	}
	k=0;
	for(i=x.size()-1;i>=0;i--)
	{
		if(x[i]!='2')
		{
			vetrai[i]=k;
		}
		k++;
	}
	cout<<"Dia can ben trai gom cac qua can: ";
	for(i=0;i<sizeof(vetrai);i++)
		cout<<"3^"<<vetrai[i]<<" ";
	cout<<"Dia can ben phai gom cac qua can: ";
	for(i=0;i<1;i++)
		cout<<"3^"<<vephai[i]<<" ";
}
int main()
{
	int n;
	cout<<"Khoi luong cua vat la: ";cin>>n;
	choncan(n);
	return 0;
}

