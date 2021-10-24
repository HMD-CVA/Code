#include <bits/stdc++.h>
using namespace std;
int n,k;
int f[100005];
int fac(int k)
{
    int kf=1;
    for(int i=1;i<=k;i++)
        kf=kf*i;
    return kf;
}
int com(int n, int k)
{
    int nf=fac(n);
    int kf=fac(k);
    int ndkf=fac(n-k);
    int res=fac(n)/(fac(k)*fac(n-k));
    return res;
}
int dp()
{
    f[1]=0;
    f[2]=1;
    for(int i=3;i<=n-k;i++)
        f[i]=(f[i-1]+f[i-2])*(i-1);
    int q=f[n-k];
    return q;
}
int main()
{
    freopen("LTHI.INP","r",stdin);
    freopen("LTHI.OUT","w",stdout);
    cin>>n>>k;
    cout<<com(n,k)*dp();
}
