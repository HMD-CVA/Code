#include <bits/stdc++.h>
#define maxx 99999999

using namespace std;

int n, m, k, s, t;
int u, v, cs, x, sum = 0;
vector<int> a[maxx];
int d[1000][1000];
int kt[1000][1000];
int trace[maxx];
void doc()
{
    cin >> n >> m >> k >> s >>t;
    while(m--)
    {
        cin >> u >> v >> cs;
        a[u].push_back(v);
        //a[v].push_back(u);
        d[u][v] = cs;
        //d[v][u] = cs;
    }
}
void process()
{
    int dem = 1;
    u = s;
    while(u != t)
    {
        for(int i = 0; i < a[u].size(); i ++)
        {
            x = a[u][i];
            if(x == t)
            {
                trace[x] = u;
                //cout<<x;
                break;
            }
        }
        /*for(int i = 1; i <= a[u].size(); i ++)
        {
            v = a[u][i];
            if(kt[u][v] == 0)
            {
                sum += d[u][v];
                trace[v] = u;
                kt[u][v] = 1;
                dem ++;
                u = v;
                continue;
            }
        }*/
    }
}
int main()
{
    freopen("tdtt.inp","r",stdin);
    freopen("tdtt.out","w",stdout);
    memset(kt,0,sizeof(kt));
    memset(d,0,sizeof(d));
    memset(trace,0,sizeof(trace));
    doc();
    cout<<a[1][1];
}
