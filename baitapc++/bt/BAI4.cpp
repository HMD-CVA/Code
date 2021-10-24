#include <bits/stdc++.h>
using namespace std;
long gt(int a)
{
	long p=1;
	for(int i=1;i<=a;i++)
	{
		p=p*i;
	}
	return p;
}
float xuli(float x)
{
	int n=1;
	float s=1;
	while(fabs((pow(x,n)/gt(n))>=pow(10,-5)))
	{
		s=s+(pow(x,n)/gt(n));
		n++;
	}
	return s;
}
int main()
{
	float x;
	cout<<"Nhap vao so thuc x: "; cin>>x;
	cout<<"S= "<<xuli(x);
	return 0;
}

