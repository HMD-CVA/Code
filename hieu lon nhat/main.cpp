#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n,k;
ll a[100001],b[100001],tree[400005];
void doc()
{
    cin>>n>>k;
    for(ll i=1; i<=n; i++)
        cin>>a[i];
}
void process()
{
    sort(a+1,a+n+1);
    for(ll i=1; i<=n; i++)
    {
        b[i] = a[i+1]-a[i];
    }
}
void create(ll root, ll l, ll r)
{
    if(l==r) tree[root]=b[l];
    else
    {
        ll mid=(l+r)/2;
        create(2*root,l,mid);
        create(2*root+1,mid+1,r);
        tree[root] = max(tree[2*root],tree[2*root+1]);
    }
}
int findmax(ll root, ll l, ll r, ll u, ll v)
{
    if (l>v || r<u)
        return INT_MIN;
    if (u<=l && r<=v)
        return tree[root];
    ll mid=(l+r)/2;
    return max(findmax(2*root,l,mid,u,v),findmax(2*root+1,mid+1,r,u,v));
}
int main()
{
    doc();
    process();
    create(1,1,n-1);
    ll x = n-k-1;
    ll kq = INT_MAX;
    for(ll i=x; i<=n-1; i++)
    {
       ll y = findmax(1,1,n,i-x+1,i);
        kq = min(kq,y);
    }
    cout<<kq;
}
