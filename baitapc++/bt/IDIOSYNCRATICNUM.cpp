#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001];
void doc()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
}
void xuli()
{
		if(a[1]%2==a[2]%2)
		{
			if(a[1]%2==0)
			{
				for(int j=1;j<=n;j++)
					if(a[j]%2==1)
						cout<<a[j];
			}
			else
				{
					for(int j=1;j<=n;j++)
						if(a[j]%2==0)
							cout<<a[j];
				}	
		}
		else
			{
				if(a[3]%2==a[1]%2)
					cout<<a[2];
				else
					cout<<a[1];
			}
}
int main()
{
	doc();
	xuli();
}

