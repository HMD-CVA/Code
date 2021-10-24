#include <bits/stdc++.h>
using namespace std;
int n,m,u,v,lt=1,dd=0;
int a[100][100];
int d[100]={0};
void doc()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        a[u][v]=1;
        a[v][u]=1;
    }
}
void DFS(int x)
{
    d[x]=1;
    for(int i=1;i<=n;i++)
    {
        if(a[x][i]==1 && d[i]==0)
        {
            d[i]==1;
            DFS(i);
        }
    }
}
void lienthong(int k)
{
    DFS(k);
    dd=0;
    for(int i=1;i<=n;i++)
        if(d[i]==1)
            dd++;
    if(dd<n)
    {
        lt++;
        for(int i=1;i<=n;i++)
        {
            if(d[i]==0)
                lienthong(i);
        }
    }
    else if(dd==n)
        cout<<lt;
}
int main()
{
   freopen("DFS.inp","r",stdin);
   freopen("DFS.out","w",stdout);
   doc();
   lienthong(1);
}
