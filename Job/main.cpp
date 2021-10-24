#include <bits/stdc++.h>

using namespace std;
ifstream f1("job.inp");
ofstream f2("job.out");
int n;
struct job
{
    int d;
    int g;
    int t;
};
job a[10000],b[10000];
void doc()
{
    f1>>n;
    for(int i=1;i<=n;i++)
    {
        f1>>a[i].d>>a[i].g;
        a[i].t=i;
    }
}
void qs(int l,int r)
{
	int i=l,j=r;
	int x=a[(l+r)/2].d;
	while(i<=j)
	{
		while(a[i].d<x) i++;
		while(a[j].d>x) j--;
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
void xuli()
{
   int d=1,h=1,s=0;
   qs(1,n);
   for(int i=1;i<=n;i++)
   {
       for(int j=i+1;j<=n;j++)
       {
           if(a[i].d==a[j].d && a[i].g<a[j].g) swap(a[i],a[j]);
       }
   }
   for(int i=1;i<=n;i++)
   {
       if(d<=a[i].d)
       {
           b[h].t=a[i].t;
           b[h].d=a[i].d;
           b[h].g=a[i].g;
           h++;
           d++;
           s=s+a[i].g;
       }
   }
    f2<<s<<endl<<d-1<<endl;
    for(int i=1;i<=h-1;i++)
        f2<<b[i].t<<" "<<i<<endl;
}
int main()
{
    doc();
    xuli();
}
