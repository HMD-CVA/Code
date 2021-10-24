#include <bits/stdc++.h>
using namespace std;
int xuli
int main()
{
	int a[1000];
	int W,c;
	cin>>W>>c;
	if(W%1000!=0)
		cout<<"0";
	else
	{
		int k=0;
		int n=4*(c+1);
		while(k<=c)
		{
		for(int i=1;i<=n;i+=4)
			{
				a[i]=1000*pow(10,k);
				a[i+1]=2000*pow(10,k);
				a[i+2]=3000*pow(10,k);
				a[i+3]=5000*pow(10,k);
				k++;
			}
		}
		int t[1000];
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=W)
			{
				if(W%a[i]==0)
					t[i]=W/a[i];
				else
					
			}
			}	
	}
}

