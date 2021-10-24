#include <bits/stdc++.h>
using namespace std;
int n,k,d=1,maxx=1;
int a[1000];
void doc()
{
    cin>>n>>k;
    for(int i=1;i<=k;i++)
        cin>>a[i];
}
void bt(int i)
{
    for(int j=1;j<=k;j++)
        if(a[j]==a[i-1]+1)
            a[j]=0;
    sort(a,a+k+1);
    d=1;
    if(a[i]+1<=n)
        a[1]=a[i]+1;
    sort(a,a+k+1);
    for(int j=i-1;j<=k;j++)
    {
        if(a[j]+1==a[j+1])
            d++;
        else
            break;
    }
    if(d>maxx)
        maxx=d;
    bt(i+1);
}
int main()
{
    freopen("LCSUB.inp","r",stdin);
    freopen("LCSUB.out","w",stdout);
    doc();
    bt(2);
    cout<<maxx;
}
