#include <bits/stdc++.h>

using namespace std;
ifstream f1("chanel.inp");
ofstream f2("chanel.out");
int n;
struct chanel
{
    int tt;
    int s;
    int t;
};
chanel a[10000],b[10000];
void doc()
{
    f1>>n;
    for(int i=1;i<=n;i++)
    {
        f1>>a[i].s>>a[i].t;
        a[i].tt=i;
    }
}
void qs(int l,int r)
{
    int i=l,j=r;
    int x=a[(l+r)/2].s;
    while(i<=j)
    {
        while(a[i].s<x) i++;
        while(a[j].s>x) j--;
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
    int kt[100000],c[100000];
    int d=0,h=1,k=1;

    qs(1,n);
    for(int i=1;i<=n;i++)
   {
       for(int j=i+1;j<=n;j++)
       {
           if(a[i].s==a[j].s && a[i].t<a[j].t) swap(a[i],a[j]);
       }
   }
    for(int i=1;i<=n;i++)
        kt[i]=1;
   for(int i=1;i<=n;i++)
   {
       if(a[i].s==0)
       {
           d++;

           for(int j=i+1;j<=n;j++)
           {
               if(a[j].s>=a[i].t && kt[j]==1 )
                {
                    d++;
                    if(kt[i]==1)
                    {
                        b[h].tt=a[i].tt;
                        h++;
                        kt[i]=0;
                    }
                    b[h].tt=a[j].tt;
                    h++;
                    kt[j]=0;

                }
           }
        c[k]=d;
        k++;

       }
       d=0;

   }
    sort(c+1,c+k,greater<int>());
    f2<<c[1]<<endl;
    for(int i=1;i<=h-1;i++)
        f2<<b[i].tt<<" ";
}
int main()
{
    doc();
    xl();
}
