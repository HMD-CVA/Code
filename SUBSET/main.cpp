#include <bits/stdc++.h>
#define oo 1000000007
using namespace std;
struct node
{
    long long even;
    long long odd;
    long long res=0;
};
node ST[500005];
long long a[100005];
long long n,q,wq,u,v;
void build(long long id, long long l, long long r)
{
    if(l==r)
    {
        if(a[l]%2==0)
        {
            ST[id].even=1;
            ST[id].odd=0;
            ST[id].res=0;
        }
        else
        {
            ST[id].even=0;
            ST[id].odd=1;
            ST[id].res=0;
        }
    }
    else
    {
        long long mid=(l+r)/2;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        ST[id].even=ST[2*id].even+ST[2*id+1].even;
        ST[id].odd=ST[2*id].odd+ST[2*id+1].odd;
    }
}
node getN(long long id, long long l, long long r, long long u, long long v)
{
    if(v<l || u>r)
        return ST[0];
    if(l>=u && r<=v)
        return ST[id];
    long long mid=(l+r)/2;
    getN(2*id,l,mid,u,v);
    getN(2*id+1,mid+1,r,u,v);
    if(ST[id].odd==0)
        ST[id].res=(pow(2,v-u+1)-1);
    else
        ST[id].res=(pow(2,v-u)-1);
    return ST[id];
}
int main()
{
    freopen("SUBSET.INP","r",stdin);
    freopen("SUBSET.OUT","w",stdout);
    cin>>n>>q;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    for(long long i=1;i<=q;i++)
    {
        cin>>wq>>u>>v;
        if(wq==1)
        {
            a[u]=v;
            build(1,1,n);
        }
        else if(wq==2)
        {
            long long e=getN(1,1,n,u,v).res;
            e%=oo;
            cout<<e<<endl;
        }
    }
}
/*void update(int id, int l, int r, int k, int b)
{
    if(l==r)
    {
        a[k]=b;
        if(b%2!=0)
        {
            ST[id].even=0;
            ST[id].odd=1;
            ST[id].res=0;
        }
        else
        {
            ST[id].even=1;
            ST[id].odd=0;
            ST[id].res=0;
        }
    }
    else
    {
        int mid=(l+r)/2;
        if(k>mid)
            update(2*id+1,mid+1,r,k,b);
        else
            update(2*id,l,mid,k,b);
    }
}*/
