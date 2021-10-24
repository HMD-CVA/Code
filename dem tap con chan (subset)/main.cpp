#include <bits/stdc++.h>
#define ll long long
#define oo 1000000007
using namespace std;
struct node
{
    ll ch;
    ll l;
};
node ST[900005];
ll a[500005];
ll n,q,x,u,v;
void build(ll id, ll l, ll r)
{
    if(l==r)
    {
        if(a[l]==2)
        {
            ST[id].ch=1;
            ST[id].l=0;
        }
        else
        {
            ST[id].ch=0;
            ST[id].l=1;
        }
    }
    else
    {
        ll mid=(l+r)/2;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        ST[id].ch=ST[2*id].ch+ST[2*id+1].ch;
        ST[id].l=ST[2*id].l+ST[2*id+1].l;
    }
}
void update(ll id, ll l, ll r, ll k, ll b)
{
    if(l==r)
    {
        if(b%2==0)
            a[k] = 2;
        else
            a[k] = 1;
        if(a[k] == 1)
        {
            ST[id].ch=1;
            ST[id].l=0;
        }
        else
        {
            ST[id].ch=0;
            ST[id].l=1;
        }
    }
    else
    {
        ll mid=(l+r)/2;
        if(k>mid)
            update(2*id+1,mid+1,r,k,b);
        else
            update(2*id,l,mid,k,b);
        ST[id].ch = ST[id*2].ch + ST[id*2+1].ch;
        ST[id].l = ST[id*2].l + ST[id*2+1].l;
    }
}
node getN(ll id, ll l, ll r, ll u, ll v)
{
    if(v<l || u>r)
        return ST[0];
    if(l>=u && r<=v)
        return ST[l];
    ll mid=(l+r)/2;
    getN(2*id,l,mid,u,v);
    getN(2*id+1,mid+1,r,u,v);
    return ST[id];
}
int main()
{
    freopen("SUBSET.INP","r",stdin);
    freopen("SUBSET.OUT","w",stdout);
    cin>>n>>q;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]%2==0)
            a[i]=2;
        else
            a[i]=1;
    }

    build(1,1,n);
    for(ll i=1;i<=q;i++)
    {
        cin>>x>>u>>v;
        if(x==1)
            update(1,1,n,u,v);
        else
        {
            ll e = 0;
        	getN(1,1,n,u,v);
        	if(u == v)
            {
                if(ST[1].l == 0)
                    cout<<"0"<<endl;
                else
                    cout<<"1"<<endl;
            }
            else
            {
                if(ST[1].l == 0)
                {
                   e = (pow(2,v-u+1)-1);
                   e%=oo;
                   cout<<e<<endl;
                }

                else
                {
                   e = (pow(2,v-u)-1);
                   e%=oo;
                   cout<<e<<endl;
                }
            }
		}
    }
}
