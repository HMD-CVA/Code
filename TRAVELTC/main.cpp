#include <bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,d[30001],x[30001],pos[30001],l[30001],r[30001];
char s[505];
long long run(long long u)
{
    for(long long i=1;i<=m;i++)
    {
        if (s[i]=='L') u=l[u];
        else u=r[u];
    }
    return u;
}
void nhap()
{
    freopen("in.inp","r",stdin);
    cin >> n >> m >> k;
    for (long long i=1;i<=n;i++)
    {
       cin >> u >> v;
       l[i]=u;
       r[i]=v;
    }
    for (long long i=1;i<=m;i++) cin >> s[i];
    for (long long i=1;i<=n;i++) x[i]=run(i);
    long long u=1,id=0;
    while(d[u]==0)
    {
        d[u]=++id;
        pos[id]=u;
        u=x[u];
    }
    cout<<pos[(k-d[u]+1)%(id-d[u]+1)+d[u]];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    nhap();
}
