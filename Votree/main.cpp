#include<bits/stdc++.h>
using namespace std;
const int maxx=70005;
const int LOG=17;
long long n,q,u,v,depth[maxx],T[maxx][18],st[4*maxx];
vector<long long> a[maxx];
void nhap()
{
    freopen("in.inp","r",stdin);
    cin >> n >> q;
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
    for (long long i=1;i<=LOG;i++) T[u][i]=T[T[u][i-1]][i-1];
    for (long long v:a[u])
        if (v==p) continue;
            else dfs(v,u);
}
long long LCA(long long u,long long v)
{
    if (depth[u]<depth[v]) swap(u,v);
    for (long long i=LOG;i>=0;i--) if (depth[T[u][i]]>=depth[v]) u=T[u][i];
    if (u==v) return u;
    for (long long i=LOG;i>=0;i--)
    if (T[u][i]!=T[v][i])
    {
        u=T[u][i];
        v=T[v][i];
    }
    return T[u][0];
}
void build(long long id, long long l, long long r)
{
    if(l==r)
    {
        st[id]=l;
        return;
    }
    long long mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id]=LCA(st[2*id],st[2*id+1]);
}
long long getlca(long long id,long long l,long long r,long long u,long long v)
{
    if (l>v || r<u) return INT_MAX;
    if (l>=u && r<=v) return st[id];
    long long mid=(l+r)/2;
    long long res1=getlca(id*2,l,mid,u,v);
    long long res2=getlca(id*2+1,mid+1,r,u,v);
    if (res1==INT_MAX) return res2;
    if (res2==INT_MAX) return res1;
    return LCA(res1,res2);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    nhap();
    dfs(1,0);
    build(1,1,n);
    for (int i=1;i<=q;i++)
    {
        cin >> u >> v;
        cout << getlca(1,1,n,u,v) << endl;
    }
}
