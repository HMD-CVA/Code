#include <bits/stdc++.h>

using namespace std;

ifstream f1("input.inp");
ofstream f2("output.out");
int n,m,v,u;
bool check[10005];
int a[500][500];
int low[10005],parent[10005],number[10005],nhanh[10005],visited[10005],h[1000][1000];
void doc()
{
    f1>>n>>m;
    for(int i=1;i<=m;i++)
    {
        f1>>u>>v;
        a[u][v]=1;
        a[v][u]=1;
    }
}
void dfs(int u)
{
    int c;
    c++;
    number[u]=c;
    low[u]=INT_MAX;
    for(int v=1;v<=n;v++)
    {
        if(a[u][v]>0)
        {
            a[v][u]=0;
            nhanh[u]++;
            if(parent[v]==0)
            {
                parent[v]=u;
                dfs(v);
                if(low[u]>low[v]) low[u]=low[v];
            }
            else
            {
                if(low[v]>number[u])
                    low[v]=number[u];
            }
        }
    }
}
void process()
{
    for(int i=1;i<=n;i++)
    {
        if(parent[i]==0)
        {
            parent[i]=-1;
            dfs(i);
        }
    }
}
void khop()
{
    int u,e=0;
    for(int i=1;i<=n;i++)
        check[i]=false;
    for(int i=1;i<=n;i++)
    {
        if(parent[i]==-1 && nhanh[i]>=2)
            e++;
    }
    for(int v=1;v<=n;v++)
    {
        u=parent[v];
        if(u!=-1 && parent[u]!=-1 && low[u]>=number[v] && check[v]==false)
            {
                check[v]=true;
                e++;
            }
    }
    f2<<e<<endl;
}
void xlcau()
{
    int d=0;
    for(int v=1;v<=n;v++)
    {
        u=parent[v];
        if(u!=-1 && low[v]<=number[v])
            d++;
    }
    f2<<d;
}
int main()
{
    doc();
    process();
    khop();
    xlcau();
}
