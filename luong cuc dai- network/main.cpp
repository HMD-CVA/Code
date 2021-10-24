#include <bits/stdc++.h>
using namespace std;
#define V 1005
bool visited[V];
int a[V][V];
int s,t;
int n,m;
bool bfs(int parent[])
{
    queue <int> q;
    memset(visited, 0, sizeof(visited));
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 1; v <=n; v++)
        {
            if (visited[v] == false && a[u][v] > 0)
            {
                if (v == t)
                {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}
int maxfl(int s, int t)
{
    int parent[V];
    int u,v;
    int max_flow = 0;
    while (bfs(parent))
    {
        int minn= INT_MAX;
        for (v=t;v!=s;v=parent[v])
        {
            u = parent[v];
            minn= min(minn, a[u][v]);
        }
        for (v=t;v!=s;v = parent[v])
        {
            u = parent[v];
            a[u][v] -= minn;
            a[v][u] += minn;
        }
        max_flow += minn;
    }
    return max_flow;
}
int main()
{
   //freopen("input.inp","r",stdin);
   cin>>n>>m>>s>>t;
   int u,v,c;
   for (int i=1;i<=m;i++)
   {
       cin>>u>>v>>c;
       a[u][v]=c;
   }

    cout <<maxfl(s, t);
}
