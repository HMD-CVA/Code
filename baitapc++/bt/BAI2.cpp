#include <bits/stdc++.h>
using namespace std;
int a[100];
int chan[100];
int le[100];
ifstream f1("BAI2.INP");
ofstream f2("BAI2.OUT");
void xuli(int a[])
{
	int i,j=0,k=0;
	int n=sizeof(a);
	for(i=0;i<n;i++)
	{
		if (a[i]%2!=0)
			{
				le[j]=a[i];
				j++;
			}
		else 
			{
				chan[k]=a[i];
				k++;
			}
	}
	sort(le,le+j);
	sort(chan,chan+k,greater<int>());
	for(i=0;i<j;i++)
		a[i]=le[i];
	for(i=j;i<j+k;i++)
		a[i]=chan[i];
}
void doc()
{
	int i=0;
	while(f1)
	{
		f1>>a[i];
		i++;
	}
	i--;
}
int main()
{
	int n;
	doc();
	xuli(a);
	n=sizeof(a);
	for(int i=0;i<n;i++)
		f2<<a[i]<<" ";
		return 0;
}

