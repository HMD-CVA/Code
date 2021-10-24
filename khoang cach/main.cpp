#include <bits/stdc++.h>
#define ll long long

using namespace std;
ifstream f1("dist.inp");
ofstream f2("dist.out");

ll n,k;
ll a[900005];
struct toado
{
    ll x;
    ll y;
};
toado st[900005];
/*void build(ll id, ll l, ll r, node p)
{
    if(l == r)
    {
        st[id].x = p.x;
        st[id].y = p.y;
    }
    ll mid = (l+r)/2;
    build(id*2,l,mid,p);
    build(id*2+1,mid+1,r,p);
    st[id].x = abs(st[id*2].x - st[id*2+1].x);
    st[id].y = abs(st[id*2].y - st[id*2+1].y);

}
ll findgcd(ll id, ll l, ll r, ll u, ll v)
{
    if (l>v || r<u)
        return 0;
    if (u<=l && r<=v)
        return min(st[id].x,st[id].y);
    ll mid=(l+r)/2;
    return
}*/
void doc()
{
    f1>>n>>k;
    for(ll i=1; i<=n; i++)
    {
        f1>>st[i].x>>st[i].y;
    }
}
void process(ll h)
{
    ll k=1;
    for(ll i=1; i<n; i++)
    {
        for(ll j=i+1; j<=n; j++)
        {
            ll e = abs(st[i].x - st[j].x);
            ll f = abs(st[i].y - st[j].y);
            a[k] = min(e,f);
            k++;
        }
    }
    sort(a+1,a+k);
    f2<<a[h];
}
int main()
{
    doc();
    process(k);
}
