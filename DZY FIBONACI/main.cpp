#include <bits/stdc++.h>
#define ll long long
#define oo 1000000009

using namespace std;

ll n,m,x,u,v;
ll a[100005], b[100005], f[100005], st[500005];

void doc()
{
    cin>>n>>m;
    for(ll i=1; i<=n; i++)
        cin>>a[i];
}
void fibo()
{
    f[1]=1;
    f[2]=1;
    //ll x=r-l+1;
    for(ll i=3; i<=n; i++)
        {
            f[i] = f[i-1]+f[i-2];
        }
    //for(ll i=1; i<=x; i++)
        //return f[i];
}
void build(ll id, ll l, ll r)
{
    if(l == r)
        st[id] = a[l];
    else
    {
        ll mid = (l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        st[id] = (st[id*2]+st[id*2+1]);
    }
}
void update(ll id, ll l, ll r, ll u, ll v)
{
    fibo();
    if(l>v || r<u)
        return;
    if(l == r)
    {
        st[id] = (st[id]+f[l-u+1])%oo;
    }
    else
    {
        ll mid = (l+r)/2;
        update(id*2,l,mid,u,v);
        update(id*2,mid+1,r,u,v);
        st[id] = (st[id*2]+st[id*2+1]);
    }
}
ll getN(ll id, ll l, ll r, ll u, ll v)
{
    if(v<l || u>r)
        return 0;
    if(l>=u && r<=v)
        return st[id]%oo;
    else
    {
        ll mid = (l+r)/2;
        return (getN(id*2,l,mid,u,v)+getN(id*2+1,mid+1,r,u,v))%oo;
    }
}
int main()
{
    freopen("inp","r",stdin);
    freopen("out","w",stdout);
    doc();
    build(1,1,n);
    //fibo(1,n);
    for(ll i=1; i<=m; i++)
    {
        cin>>x>>u>>v;
        if(x == 1)
        {
            update(1,1,n,u,v);
            //build(1,1,n);
        }
        else
            cout<<getN(1,1,n,u,v)%oo<<endl;
    }
    //for(int i=1;i<=n;i++)
        //cout<<a[i]<<" ";
}
