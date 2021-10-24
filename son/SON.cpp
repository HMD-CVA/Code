#include <bits/stdc++.h>

using namespace std;
ifstream f1("son.inp");
ofstream f2("son.out");
int n,m;
int x[100000],kt[100000],d=0;
void doc()
{
    f1>>n>>m;
}
void gn()
{
    for(int i=1;i<=m;i++)
    {
        f2<<x[i]<<" ";
    }
    f2<<endl;
}
void ql(int i)
{
	for(int j=1;j<=n;j++)
	{
		if(kt[j]==0)
		{
			x[i]=j;
			kt[j]=1;
			if(i==m)
			{
				gn();
				d++;
			}
			else
			{
				ql(i+1);
			}
			kt[j]=0;
		}

	}
}
int main()
{
    doc();
    ql(1);
    f2<<d;
}
