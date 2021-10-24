#include <bits/stdc++.h>
#define ll long long
#define maxx 10005
#define oo 100000009

using namespace std;

int n, m;
int u, v, c;
vector<int> a[maxx];
int start, target;
int w[100][100];
int f[100][100];
int T[maxx];
int l[maxx];
int del[maxx];
void doc()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i ++)
    {
        cin >> u >> v >> c;
        a[u].push_back(v);
        a[v].push_back(u);
        w[u][v] = c;
        w[v][u] = c;
    }
}
void Merge(int s, int t)
{
    for(int v = 1; v <= n; v ++)
    {
        if(del[v] == 0 && v != s && v != t)
        {
            w[s][v] += w[v][t];
            w[v][s] += w[s][v];
        }
        del[t] = 1;
    }
}
int Maxstick(int T[maxx], int l[maxx])
{
    int temp = INT_MIN;
    for(int v = 1; v <= n; v ++)
    {
        if(del[v] == 0 && T[v] == 0 && temp < l[v])
        {
            u = v;
            temp = l[v];
        }
    }
    return u;
}
int mincut(int n)
{
    int j = 1, i = 1;
    int x, y;
    memset(T,0,sizeof(T));
    memset(l,0,sizeof(l));
    if(n == 2)
    {
        for(int k = 1; k <= n; k ++)
        {
            if(del[k] == 0)
            {
                if(j == 1)
                {
                    x = k;
                    j++;
                }
                else
                    y = k;
            }
        }
        return w[x][y];
    }
}
main()
{

}
