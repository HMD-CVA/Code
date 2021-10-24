#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll n, q;
ll x, u, v;
ll parentct[300000], parentdn[300000], dn[300000], ct[300000];
typedef pair<ll, ll> ii;
queue<ii> dct, ddn;

ll findsetct(ll u)
{
    if (parentct[u] != u)
        parentct[u] = findsetct(parentct[u]);
    return parentct[u];
}
void unionsetct(ll u, ll v)
{
    ll r1 = findsetct(u);
    ll r2 = findsetct(v);
    if (r1 == r2)
        return;
    if (ct[r1] == ct[r2])
        ct[r1]++;
    if (ct[r1] < ct[r2])
        parentct[r1] = r2;
    else
        parentct[r2] = r1;
}
ll findsetdn(ll u)
{
    if (parentdn[u] != u)
        parentdn[u] = findsetdn(parentdn[u]);
    return parentdn[u];
}
void unionsetdn(ll u, ll v)
{
    ll r1 = findsetdn(u);
    ll r2 = findsetdn(v);
    if (r1 == r2)
        return;
    if (dn[r1] == dn[r2])
        dn[r1]++;
    if (dn[r1] < dn[r2])
        parentdn[r1] = r2;
    else
        parentdn[r2] = r1;
}
void kt()
{
    while (!dct.empty())
    {
        ll u = dct.front().first;
        ll v = dct.front().second;
        if (findsetdn(u) == findsetdn(v))
            dct.pop();
        else
            break;
    }
    while (!ddn.empty())
    {
        ll u = ddn.front().first;
        ll v = ddn.front().second;
        if (findsetct(u) == findsetct(v))
            ddn.pop();
        else
            break;
    }
    if (dct.size() == 0 && ddn.size() == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int main()
{
   // freopen("inp","r",stdin);
    cin>>n>>q;
    for(ll i = 1; i <= n; i++)
        parentct[i] = parentdn[i] = i;
    for(ll i = 1; i <= q; i++)
    {
        cin>>x>>u>>v;
        if (x == 1) {
            dct.push(make_pair(u,v));
            unionsetct(u,v);
        } else {
            ddn.push(make_pair(u,v));
            unionsetdn(u,v);
        }
        kt();
    }
}
