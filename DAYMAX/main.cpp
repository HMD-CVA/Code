#include <bits/stdc++.h>
using namespace std;
int n,k,maxx,d,c,m;
int a[1000];
void doc()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
}
int sum(int a[],int p,int q)
{
    int s=0;
    for(int i=p;i<=q;i++)
        s=s+a[i];
    return s;
}
void xuli()
{
    maxx=a[1];
    for(int i=2;i<=n;i++)
        if(a[i]>maxx)
        {
            maxx=a[i];
            m=i;
        }
    int r=maxx;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            k=sum(a,i,j);
            if(k>maxx)
            {
                maxx=k;
                d=i;
                c=j;
            }
        }
        if(maxx==r)
        {
            cout<<m<<endl;
            cout<<maxx;
        }
    }
    cout<<d<<" "<<c<<endl;
    cout<<maxx;
}
int main()
{
    freopen("DAYMAX.inp","r",stdin);
    freopen("DAYMAX.out","w",stdout);
    doc();
    xuli();
}
