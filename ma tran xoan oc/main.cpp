#include<bits/stdc++.h>
using namespace std;
ifstream f1("bank.inp");
ofstream f2("bank.out");
int n;
int a[10000][10000];
void doc()
{
    f1>>n;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=n;j++)
            f1>>a[i][j];
}
void xuli()
{
	int s=0,sum=0;
	int b=n*3;
	int x=0,y=0,z=0,c=0;
	//int u=n,v=3;
	while(s!=b)
	{
		for(int i=1;i<=n;i++)
        {
            s++;
            x=x*2+a[1][i];
        }
        for(int j=2;j<=3;j++)
        {
            s++;
            y=y*2+a[j][n];
        }
        for(int h=n-1;h>=1;h--)
        {
            s++;
            z=z*2+a[3][h];
            f2<<z<<" ";
        }
        for(int k=1;k<=n-1;k++)
        {
            s++;
            c=c*2+a[2][k];
        }
	}
	sum=((x*2+y)*2+z)*2+c;
	f2<<sum;
}
int main()
{
	doc();
	xuli();
}
