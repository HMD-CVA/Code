#include <bits/stdc++.h>
#define ll long long
#define MAX 300005

using namespace std;

ll n,m,x,u,v;
ll fz[MAX], rankk[MAX], a[MAX];
ll findset(ll u)
{
    if(fz[u] == u)
        return u;
    fz[u] = findset(fz[u]);
    return fz[u];
}
void unionset(ll u, ll v)
{
    ll r1 = findset(u);
    ll r2 = findset(v);
    if(r1 == r2)
        return;
    if(rankk[r1] == rankk[r2])
        rankk[r1]++;
    if(rankk[r1] < rankk[r2])
        fz[r1] = r2;
    else
        fz[r2] = r1;
}
void kt(ll u, ll v)
{
    if(findset(u) == findset(v))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
int main()
{
    freopen("RESTRUCT.INP","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(rankk,1,sizeof(rankk));
    cin >> n >> m;
    for(ll i = 1 ;i <= n;i ++)
        fz[i] = i;
    for(ll i = 1; i <= m; i ++)
    {
        cin >> x >> u >> v;
        if(x == 1)
            unionset(u,v);
        else if(x == 2)
        {
            for(ll i = u; i <= v; i++)
            {
                unionset(i,i+1);
            }
        }
        else if(x == 3)
        {
            kt(u,v);

        }
    }
}
