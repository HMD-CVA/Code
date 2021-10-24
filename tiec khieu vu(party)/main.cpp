#include <bits/stdc++.h>
#define ll long long
#define MAX 300000

using namespace std;

ll n, m, w, x, y, u, v;
ll sw[MAX], sb[MAX], b[MAX], dp[MAX], ww[MAX], fz[MAX];
vector <ll> V[MAX];
ll findset(ll u)
{
    if(u == fz[u])
        return u;
    return fz[u] = findset(fz[u]);
}
void doc()
{
    cin >> n >> m >> w;
    for(ll i = 1; i <= n; i ++)
        cin >> ww[i];
    for(ll i = 1; i <= n; i ++)
        cin >> b[i];
    for(ll i = 1; i <= n; i ++)
        fz[i] = i;
    for(ll i = 1; i <= m; i ++)
    {
        cin >> x >> y;
        fz[findset(y)] = findset(x);
    }
}
void process()
{
    for( ll i = 1; i <= n; i ++)
    {
        sw[findset(i)] += ww[i];
        sb[findset(i)] += b[i];
        V[findset(i)].push_back(i);
    }
    for( ll i = 1; i <= n; i++)
    {
        for( ll j = w; j>=0; j--)
        {

            //u = V[i].front();
           //while(!V[i].empty())
           for(ll k = 0; k < V[i].size(); k ++)
                {
                    u = V[i][k];
                if(j >= ww[u])
                {
                    dp[j] = max(dp[j],dp[j-ww[u]]+b[u]);
                   // V[i].pop_back();
                    //continue;
                }

                }

            if(j >= sw[i])
                dp[j] = max(dp[j],dp[j-sw[i]]+sb[i]);
        }
    }
        cout<<dp[w];
}
int main()
{
    freopen("PARTY.INP","r",stdin);
    //freopen("PARTY.OUT","w",stdout);
    doc();
    process();
    //cin >> n >> m >> w;

}
