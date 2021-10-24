#include <bits/stdc++.h>
#define oo 1000000000
using namespace std;
long long n,m,s,t;
long long u,v,w;
long long c[1005][1005];
long long f[1005][1005];
long long d[1005];
vector <long long> vt[1005];
void doc()
{
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        vt[u].push_back(v);
        vt[v].push_back(u);
        c[u][v]=w;
    }
}
bool find_set(int s, int t)
{
    queue <long long> q;
    for(int i=1;i<=n;i++)
        d[i]=0;
    d[s]=oo;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(u==t)
            return true;
        for(int v:vt[u])
        {
            if(d[v]==0 && f[u][v]<c[u][v])
            {
                d[v]=u;
                q.push(v);
            }
        }
    }
    return false;
}
void up_flow()
{
    long long minn,u,v;
    minn=oo;
    v=t;
    while(v!=s)
    {
        u=d[v];
        if(c[u][v]-f[u][v]<minn)
            minn=c[u][v]-f[u][v];
        v=u;
    }
    v=t;
    while(v!=s)
    {
        u=d[v];
        f[u][v]+=minn;
        f[v][u]-=minn;
        v=u;
    }
}
long long result(int u)
{
    long long res=0;
    for(int v:vt[u])
        res+=f[u][v];
    return res;
}
int main()
{
    freopen("MAXFLOW.INP","r",stdin);
    freopen("MAXFLOW.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    doc();
    while(find_set(s,t))
        up_flow();
    cout<<result(s);
}
