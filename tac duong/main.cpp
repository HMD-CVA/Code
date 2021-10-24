#include <bits/stdc++.h>
#define ll long long

using namespace std;
ifstream f1("tacduong.inp");
ofstream f2("tacduong.out");
ll n,m,u,v;
ll x,y,z,p,q,r;
ll a[1000][1000];
ll visit[10000];
void doc()
{
    f1>>n>>m;
    for(ll i=1;i<=m;i++)
    {
        f1>>u>>v;
        a[u][v]=1;
        a[v][u]=1;
    }
}
void dfs(ll u)
{
    visit[u]=1;
    for(ll i=1;i<=n;i++)
    {
        if(a[u][i]==1 && visit[i]==0)
        {
            dfs(i);
        }
    }
}
void processc(ll b, ll c, ll d, ll e)
{
    int tam;
    tam=a[d][e];
    a[d][e]=0;
    a[e][d]=0;
    dfs(b);
    if(visit[c]==1) f2<<"yes"<<endl;
    else f2<<"no"<<endl;
    a[d][e]=tam;
    a[e][d]=tam;

}
void processk(ll b, ll c, ll d)
{
    int pr[1000];
    for(ll i=1;i<=n;i++)
    {
        if(a[i][d]==1)
        {
            pr[i]=1;
            a[i][d]=0;
            a[d][i]=0;
        }
    }
    dfs(b);
    if(visit[c]==1) f2<<"yes"<<endl;
    else f2<<"no"<<endl;
    for(ll i=1;i<=n;i++)
    {
        if(pr[i]==1)
        {
            a[i][d]=1;
            a[d][i]=1;
        }
    }
}
int main()
{
    doc();
    f1>>x;
    for(ll i=1;i<=x;i++)
    {
        f1>>y;
        if(y==1)
        {
            f1>>z>>p>>q>>r;
            processc(z,p,q,r);
        }
        if(y==2)
        {
            f1>>z>>p>>q;
            processk(z,p,q);
        }
    }
}
