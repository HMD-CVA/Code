#include<bits/stdc++.h>
using namespace std;
long long n,u,v,depth[200005],T[200005][19],re,kq=0;
vector<long long> a[200005];
void nhap()
{
    freopen("in.inp","r",stdin);
    cin >> n;
    for (long long i=1;i<=n-1;i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}
void dfs(long long u,long long p)
{
    depth[u]=depth[p]+1;
    T[u][0]=p;
    for (long long i=1;i<19;i++) T[u][i]=T[T[u][i-1]][i-1];
    for (long long v:a[u])
        if (v==p) continue;
            else dfs(v,u);
}
long long LCA(long long u,long long v)
{
    if (depth[u]<depth[v]) swap(u,v);
    for (long long i=19-1;i>=0;i--) if (depth[T[u][i]]>=depth[v]) u=T[u][i];
    if (u==v) return u;
    for (long long i=19-1;i>=0;i--)
    if (T[u][i]!=T[v][i])
    {
        u=T[u][i];
        v=T[v][i];
    }
    return T[u][0];
}
void xl()
{
    long long j;
    for (long long i=1;i<=n/2;i++)
        for (int j=2*i;j<=n;j+=i)
            kq+=(depth[i]+depth[j]-2*depth[LCA(i,j)])+1;
    cout << kq;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    nhap();
    dfs(1,0);
    xl();
}
