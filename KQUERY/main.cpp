#include <bits/stdc++.h>
using namespace std;
int n,q;

int a[30005],b[30005], ST[30005];

void cre(int id, int l, int r)
{
    if(r==l)
    {
        ST[id]=1;
        return;
    }
    int mid=(l+r)/2;
    cre(id*2,l,mid);
    cre(id*2+1,mid+1,r);
    ST[id]=ST[2*id]+ST[2*id+1];
}
void update(int id, int l, int r, int u)
{
    if(u<l || u>r)
        return;
    if(l==r)
    {
        ST[id]=0;
        return;
    }
    int mid=(l+r)/2;
    update(2*id,l,mid,u);
    update(2*id+1,mid+1,r,u);
    ST[id]=ST[2*id]+ST[2*id+1];
}
int res(int id, int l, int r, int u, int v)
{
    if(v<l || u>r)
        return 0;
    if(u<=l && r<=v)
        return ST[id];
    int mid=(l+r)/2;
    return res(2*id,l,mid,u,v)+res(2*id+1,mid+1,r,u,v);
}
int main()
{
    freopen("KQUERY.INP","r",stdin);
    freopen("KQUERY.OUT","w",stdout);
    cin>>n;
    int id[30005];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        id[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
            if(a[i]>=a[j])
        {
            swap(a[i],a[j]);
            swap(id[i],id[j]);
        }
    }

    struct query
    {
        int a,b,c;
    };
    query qrs[30005];
    cin>>q;
    for(int i=1;i<=q;i++)
        cin>>qrs[i].a>>qrs[i].b>>qrs[i].c;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
            if(qrs[i].c>=qrs[j].c)
        {
            swap(qrs[i],qrs[j]);
        }
    }
    cre(1,1,n);
    int i=1;
    for(query q: qrs)
    {
        while(a[id[i]]<=q.c)
        {
            b[id[i]]=0;
            update(1,1,n,1);
            i++;
        }
        cout<<res(1,1,n,q.a,q.b);
    }
}
