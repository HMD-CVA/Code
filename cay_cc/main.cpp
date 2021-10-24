#include <bits/stdc++.h>
#define ll long long
#define oo 9999999999
#define MAX 1005

using namespace std;

ll n, u ,v;
ll a[MAX][MAX];
ll visit[200005], d[200005];
void doc()
{
    cin >> n;
    for(ll i = 1; i <= n-1; i ++)
    {
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
        d[u]++;
        d[v]++;
    }
}
void dfs(ll u)
{
    visit[u] = 1;
    for(ll v = 1; v <= n; v ++)
    {
        if(visit[v] == 0 && a[u][v] == 1)
            dfs(v);
    }
}
void process()
{
    sort(d+1,d+n+1,greater<int>() );
    cout << d[1];
}
int main()
{
    freopen("cc.inp","r",stdin);
    freopen("cc.out","w",stdout);
    doc();
    process();
}
