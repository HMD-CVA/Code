#include<bits/stdc++.h>
#define maxx 300009
using namespace std;
long long n,q,u,v,s1,s2,t,depth[300009],T[300009][21],w,len[maxx],len2[maxx],x,y,z;
typedef pair<long long, long long> ll;
vector<ll> a[300009];
void dfs(long long u,long long p)
{
    depth[u]=depth[p]+1;
    T[u][0]=p;
    for (long long i=1;i<21;i++) T[u][i]=T[T[u][i-1]][i-1];
    for (auto v:a[u])
        if (v.first!=p)
        {
            len[v.first]=len[u]+v.second;
            dfs(v.first,u);
            int x=v.first;
            len2[u]=max(len2[u],len2[x]+v.second);
        }
}
long long LCA(long long u,long long v)
{
    if (depth[u]<depth[v]) swap(u,v);
    for (long long i=21-1;i>=0;i--) if (depth[T[u][i]]>=depth[v]) u=T[u][i];
    if (u==v) return u;
    for (long long i=21-1;i>=0;i--)
    if (T[u][i]!=T[v][i])
    {
        u=T[u][i];
        v=T[v][i];
    }
    return T[u][0];
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        for (int i=1;i<=n;i++) a[i].clear();
        memset(len,0,sizeof(len));
        memset(len2,0,sizeof(len2));
        memset(depth,0,sizeof(depth));
        memset(T,0,sizeof(T));
        for (long long i=1;i<=n-1;i++)
        {
            cin >> u >> v >> w;
            a[u].push_back(make_pair(v,w));
            a[v].push_back(make_pair(u,w));
        }
        len[1]=0;
        dfs(1,-1);
        while(q--)
        {
            cin >> x >> y >> z;
            s1=len[x]+len[y]-2*len[LCA(x,y)];
            s2=len2[x]+len2[y]+z;
            cout << max(s1,s2) << "\n;
        }
    }
}
