#include <bits/stdc++.h>
#define oo 1000000009
using namespace std;
long long n,m,q,u,v;
long long a[300009], ST[1200036], Fibo[300009];

void build(long long id, long long l, long long r)
{
    if(l==r)
        ST[id]=a[l];
    else
    {
        long long mid=(l+r)/2;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        ST[id]=ST[2*id]+ST[2*id+1];
    }
}
void update(long long id, long long l, long long r, long long u, long long v)
{
    if(v<l || u>r)
        return;
    if(l==r)
    {
        ST[id]=(ST[id]+Fibo[l-u+1])%oo;
        return;
    }
    long long mid=(l+r)/2;
    update(2*id,l,mid,u,v);
    update(2*id+1,mid+1,r,u,v);
    ST[id]=ST[2*id]+ST[2*id+1];
}
long long getS(long long id, long long l, long long r, long long u, long long v)
{
    if(v<l || u>r)
        return 0;
    if(l>=u && r<=v)
        return ST[id];
    long long mid=(l+r)/2;
    return (getS(2*id,l,mid,u,v)+getS(2*id+1,mid+1,r,u,v))%oo;
}
void creFi()
{
    Fibo[1]=1;
    Fibo[2]=1;
    for(long long j=3;j<=300009;j++)
        Fibo[j]=(Fibo[j-1]+Fibo[j-2])%oo;
}
int main()
{
    freopen("DZYFIBO.INP","r",stdin);
    freopen("DZYFIBO.OUT","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    creFi()
    for(long long i=1;i<=m;i++)
    {
        cin>>q>>u>>v;
        if(q==1)
            update(1,1,n,u,v);
        else
            cout<<getS(1,1,n,u,v)<<endl;
    }
}

