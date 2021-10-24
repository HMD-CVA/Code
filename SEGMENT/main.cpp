#include <bits/stdc++.h>
using namespace std;
string s;
int n,l,r;
struct Node
{
    int open;
    int close;
    int data;
};
Node ST[4000005];
void calc(Node ST[],int x)
{
    int minn=min(ST[2*x].open, ST[2*x+1].close);
    ST[x].data=ST[2*x].data+ST[2*x+1].data+minn*2;
    ST[x].open=ST[2*x].open+ST[2*x+1].open-minn;
    ST[x].close=ST[2*x].close+ST[2*x+1].close-minn;
}
void cre(int x, int l, int r)
{
    if(l==r)
    {
        if(s[l-1]=='(')
        {
            ST[x].open=1;
            ST[x].close=0;
            ST[x].data=0;
        }
        else
        {
            ST[x].open=0;
            ST[x].close=1;
            ST[x].data=0;
        }
        return;
    }
    int mid=(l+r)/2;
    cre(2*x, l, mid);
    cre(2*x+1, mid+1, r);
    calc(ST,x);
}
Node res(int x, int l, int r, int u, int v)
{
    Node p,p1,p2;
    if(l>v || r<u)
    {
        p.open=0;
        p.close=0;
        p.data=0;
        return p;
    }
    if(l>=u && r<=v)
        return ST[x];
    int mid=(l+r)/2;
    p1=res(2*x,l,mid,u,v);
    p2=res(2*x+1,mid+1,r,u,v);
    int minn=min(p1.open, p2.close);
    p.data=p1.data+p2.data+minn*2;
    p.open=p1.open+p2.open-minn;
    p.close=p1.close+p2.close-minn;
    return p;
}
int main()
{
    freopen("SEGMENT.INP","r",stdin);
    freopen("SEGMENT.OUT","w",stdout);
    cin>>s;
    cin>>n;
    int k=s.length();
    cre(1,1,k);
    for(int i=1;i<=n;i++)
    {
        cin>>l>>r;
        Node kq=res(1,1,k,l,r);
        cout<<kq.data<<endl;
    }
}
