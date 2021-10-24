#include <bits/stdc++.h>
#define oo INT_MAX
using namespace std;
int n,m,k,s,f;
int cnt=1,p;
int c[5005][5005];
int d[5005];
int trace[5005];
vector <int> vt[5005];
void doc()
{
    cin>>n>>m>>k>>s>>f;
    int u,v,c;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        vt[u].push_back(v);
        vt[v].push_back(u);
        cin>>c[u][v];
    }
}
void find_set(int s, int f)
{
    int x=0;
    int minn=oo;
    for(int v:vt[s])
    {
        if(c[s][v]<minn && d[v]==0)
        {
            minn=c[s][v];
            x=v;
        }
    }
    if(minn==oo)
    {
        d[s]=1;
        find_set(p,f);
    }
    else
    {
        if(x==f)
            result();
        else
        {
            d[x]=1;
            trace[x]=s;
            p=trace[x];
            find_set(x,f);
            cnt++;
        }
    }
}
int result()
{
    cout<<cnt;
}
int main()
{
    freopen("INFOEX.INP","r",stdin);
    freopen("INFOEX.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    doc();
    for(int i=1;i<=n;i++)
        d[i]=0;
    d[s]=1;
    trace[s]=s;
}
