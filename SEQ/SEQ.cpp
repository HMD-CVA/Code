#include <bits/stdc++.h>
using namespace std;
int64_t n,k,p,q;
int64_t a[100005],b[100005],dif[100005],ST[400005];
void build(int64_t id, int64_t l, int64_t r)
{
    if(l==r)
        ST[id]=dif[l];
    else
    {
        int64_t mid=(l+r)/2;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        ST[id]=__gcd(ST[2*id],ST[2*id+1]);
    }
}
int getGCD(int64_t id, int64_t l, int64_t r, int64_t u, int64_t v)
{
    if(v<l || u>r)
        return 0;
    if(u<=l && v>=r)
        return ST[id];
    int64_t mid=(l+r)/2;
    return __gcd(getGCD(2*id,l,mid,u,v),getGCD(2*id+1,mid+1,r,u,v));

}
int main()
{
    freopen("SEQ.INP","r",stdin);
    freopen("SEQ.OUT","w",stdout);
    cin>>n>>k;
    for(int64_t i=1;i<=n;i++)
        cin>>a[i];
    for(int64_t i=1;i<=n;i++)
    {
        cin>>b[i];
        dif[i]=abs(a[i]-b[i]);
    }
    build(1,1,n);
    for(int64_t i=1;i<=k;i++)
    {
        cin>>p>>q;
        cout<<getGCD(1,1,n,p,q)<<endl;
    }
}
