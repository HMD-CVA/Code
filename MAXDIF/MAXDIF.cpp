#include <bits/stdc++.h>
using namespace std;
int64_t n,k,res=INT_MAX;
int64_t ST[400005];
int64_t a[100005],b[100005];
void build(int64_t id, int64_t l, int64_t r)
{
    if(l==r)
        ST[id]=b[l];
    else
    {
        int64_t mid=(l+r)/2;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        ST[id]=max(ST[2*id],ST[2*id+1]);
    }
}
int64_t getM(int64_t id, int64_t l, int64_t r, int64_t u, int64_t v)
{
    if(v<l || u>r)
        return INT_MIN;
    if(u<=l && v>=r)
        return ST[id];
    int64_t mid=(l+r)/2;
    return max(getM(2*id,l,mid,u,v),getM(2*id+1,mid+1,r,u,v));
}
int main()
{
    freopen("MAXDIF.INP","r",stdin);
    freopen("MAXDIF.OUT","w",stdout);
    cin>>n>>k;
    for(int64_t i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int64_t i=1;i<n;i++)
        b[i]=a[i+1]-a[i];
    build(1,1,n);
    int64_t p=n-k-1;
    for(int64_t i=p;i<n;i++)
    {
        int64_t c=getM(1,1,n,i-p+1,i);
        res=min(res,c);
    }
    cout<<res;
}
