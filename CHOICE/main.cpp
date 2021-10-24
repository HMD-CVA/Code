#include <bits/stdc++.h>
using namespace std;
int maxx=0;
int d=0,d1=0,d2=0;
int z,n,k,m;
struct data
{
    int cm;
    int lv;
};
data a[1001];
void doc()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].cm>>a[i].lv;
}
int fre(int k)
{
    int freK=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i].cm==k || a[i].lv==k)
            freK++;
    }
    return freK;
}
void xuli()
{
    for(int i=1;i<=n;i++)
    {
        k=a[i].cm;
        m=a[i].lv;
        d1=fre(k);
        d2=fre(m);
        d=max(d1,d2);
        if(d>maxx)
        {
            maxx=d;
            if(d==d1) z=k;
            else z=m;
        }
    }
    cout<<maxx<<endl;
    for(int i=1;i<=n;i++)
    {
        if(a[i].cm==z || a[i].lv==z)
            cout<<i<<endl;
    }
}
int main()
{
    freopen("CHOICE.inp","r",stdin);
    freopen("CHOICE.out","w",stdout);
    doc();
    xuli();
}
