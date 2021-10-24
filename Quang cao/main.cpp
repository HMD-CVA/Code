#include <bits/stdc++.h>

using namespace std;
//ifstream f1("qc.inp");
//ofstream f2("qc.out");
int n,m,u,v;
int a[10000][10000];
int visited[100000];
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
void DFS(int u)
{
    visited[u]=1;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0 && a[u][i]==1)
            DFS(i);
    }
}
void xl()
{
    int d=1;
    DFS(1);
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
            {
                d++;
                DFS(i);
            }
    }
    cout<<m-n+d;
}
int main()
{
    doc();
    xl();
}
