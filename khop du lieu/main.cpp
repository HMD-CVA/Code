#include <bits/stdc++.h>
#define ll long long

using namespace std;
//ifstream f1("seq.inp");
//ofstream f2("seq.out");

ll n,k,u,v;
ll a[100005],b[100005],c[100005],st[400005];
void doc()
{
    cin>>n>>k;
    for(ll i=1; i<=n; i++)
        cin>>a[i];
    for(ll i=1; i<=n; i++)
        cin>>b[i];
    for(ll i=1; i<=n; i++)
        c[i] = abs(a[i]-b[i]);
}
void create(ll id, ll l, ll r)
{
    if(l == r) st[id] = c[l];
    else
    {
        ll mid = (l+r)/2;
        create(2*id,l,mid);
        create(2*id+1,mid+1,r);
        st[id] = __gcd(st[2*id],st[2*id+1]);
    }
}
ll findgcd(ll id, ll l, ll r, ll u, ll v)
{
    if (l>v || r<u)
        return 0;
    if (u<=l && r<=v)
        return st[id];
    ll mid=(l+r)/2;
    return __gcd(findgcd(2*id,l,mid,u,v),findgcd(2*id+1,mid+1,r,u,v));
}
int main()
{
    doc();
    //process();
    create(1,1,n);
    for(ll i=1; i<=k; i++)
    {
       cin>>u>>v;
       cout<<findgcd(1,1,n,u,v)<<endl;
    }
}
