#include <bits/stdc++.h>
using namespace std;
long long n,k,p,q;
long long a[100005],b[100005],dif[100005],ST[400005];
void build(long long id, long long l, long long r)
{
    if(l==r)
        ST[id]=dif[l];
    else
    {
        long long mid=(l+r)/2;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        ST[id]=__gcd(ST[2*id],ST[2*id+1]);
    }
}
int getGCD(long long id, long long l, long long r, long long u, long long v)
{
    if(v<l || u>r)
        return 0;
    if(u<=l && v>=r)
        return ST[id];
    long long mid=(l+r)/2;
    return __gcd(getGCD(2*id,l,mid,u,v),getGCD(2*id+1,mid+1,r,u,v));

}
int main()
{
    freopen("SEQ.INP","r",stdin);
    freopen("SEQ.OUT","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    for(long long i=1;i<=n;i++)
    {
        cin>>b[i];
        dif[i]=abs(a[i]-b[i]);
    }
    build(1,1,n);
    for(long long i=1;i<=k;i++)
    {
        cin>>p>>q;
        cout<<getGCD(1,1,n,p,q)<<endl;
    }
}
