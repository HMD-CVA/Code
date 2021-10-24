#include<bits/stdc++.h>
using namespace std;
int n,q,u,v,depth[100005],T[100005][19],w;
vector<int> a[100005];
void nhap()
{
    //freopen("in.inp","r",stdin);
    cin >> n >> q;
    for (int i=1;i<=n-1;i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}
void dfs(int u,int p)
{
    depth[u]=depth[p]+1;
    T[u][0]=p;
    for (int i=1;i<19;i++) T[u][i]=T[T[u][i-1]][i-1];
    for (int v:a[u])
        if (v==p) continue;
            else dfs(v,u);
}
int LCA(int u,int v)
{
    if (depth[u]<depth[v]) swap(u,v);
    for (int i=19-1;i>=0;i--) if (depth[T[u][i]]>=depth[v]) u=T[u][i];
    if (u==v) return u;
    for (int i=19-1;i>=0;i--)
    if (T[u][i]!=T[v][i])
    {
        u=T[u][i];
        v=T[v][i];
    }
    return T[u][0];
}
bool check(int u,int v,int w)
{
    if (LCA(u,w)==w && LCA(u,v)==LCA(w,v)) return true;
    if (LCA(v,w)==w && LCA(u,v)==LCA(w,u)) return true;
    return false;
}
int kt(int u, int v, int w)
{
    if (LCA(u,w)==w && LCA(u,v)==LCA(w,v)) return 1;
    if (LCA(v,w)==w && LCA(u,v)==LCA(w,u)) return 1;
    return 0;
}
void xl()
{
    while(q--)
    {
        cin >> u >> v >> w;
        cout << kt(u,v,w) << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    nhap();
    dfs(1,0);
    xl();
}
