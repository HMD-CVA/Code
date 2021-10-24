#include <bits/stdc++.h>
using namespace std;
int n,p,q,x,y,k;
struct node
{
    int val=0;
    int lazy=0;
};
node STL[50005];
void pushdwn(int id)
{
    STL[2*id].lazy+=STL[id].lazy;
    STL[2*id].val+=STL[id].lazy;
    STL[2*id+1].lazy+=STL[id].lazy;
    STL[2*id+1].val+=STL[id].lazy;
}
void cre(int id, int l, int r, int u, int v, int x)
{
    if(l>v || r<u)
        return;
    if(l>=u && r<=v)
    {
        STL[id].val+=x;
        STL[id].lazy+=x;
        return;
    }
    int mid=(l+r)/2;
    pushdwn(id);
    cre(2*id,l,mid,u,v,x);
    cre(2*id+1,mid+1,r,u,v,x);
    STL[id].val=max(STL[2*id].val,STL[2*id+1].val);
}
int query2(int id, int l, int r, int u, int v)
{
    if(l>v || r<u)
        return INT_MIN;
    if(u>=l && v<=r)
        return STL[id].val;
    int mid=(l+r)/2;
    return max(query2(2*id,l,mid,u,v),query2(2*id+1,mid+1,r,u,v));
}
int main()
{
    /*freopen("MAXVER2.INP","r",stdin);
    freopen("MAXVER2.OUT","w",stdout);*/
    cin>>n>>p;
    for(int i=1;i<=p;i++)
    {
        cin>>q;
        if(q==0)
        {
            cin>>x>>y>>k;
            cre(1,1,n,x,y,k);
        }
        else
        {
            cin>>x>>y;
            cout<<query2(1,1,n,x,y);
        }
    }
}
