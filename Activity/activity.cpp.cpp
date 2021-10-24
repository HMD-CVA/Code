#include <bits/stdc++.h>

using namespace std;
ifstream f1("activity.inp");
ofstream f2("activity.out");
int n;
struct activity
{
    int t;
    int bd;
    int kt;
};
activity a[100000],b[100000];
void doc()
{
    f1>>n;
    for(int i=1;i<=n;i++)
    {
        f1>>a[i].bd>>a[i].kt;
        a[i].t=i;
    }
}
void qs(int l,int r)
{
	int i=l,j=r;
	int x=a[(l+r)/2].bd;
	while(i<=j)
	{
		while(a[i].bd<x) i++;
		while(a[j].bd>x) j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(l<j) qs(l,j);
	if(i<r) qs(i,r);
}
void xl()
{
    int kt[100000];
    for(int i=1;i<=n;i++)
        kt[i]=1;
    int h=1,d=0;
    qs(1,n);
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i].bd==a[j].bd && kt[i]==1 && kt[j]==1)
            {
                if(a[i].kt<a[j].kt)
                {
                    kt[j]=0;
                    b[h].bd=a[i].bd;
                    b[h].kt=a[i].kt;
                    b[h].t=a[i].t;
                    h++;
                    d++;
                }
                else
                {
                    kt[i]=0;
                   b[h].bd=a[j].bd;
                    b[h].kt=a[j].kt;
                    b[h].t=a[j].t;
                    h++;
                    d++;
                }
            }
            if(a[i].bd!=a[j].bd && kt[i]==1 && kt[j]==1)
            {
                if(a[j].bd>=a[i].kt)
                {
                    kt[j]=0;
                    b[h].bd=a[j].bd;
                    b[h].kt=a[j].kt;
                    b[h].t=a[j].t;
                    h++;
                    d++;
                }
            }
        }
    }
    f2<<d<<endl;
    for(int i=1;i<=h-1;i++)
        f2<<b[i].t<<" ";
}
int main()
{
    doc();
    xl();
}
