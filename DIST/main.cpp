#include <bits/stdc++.h>
using namespace std;
int n,k;
struct coordnts
{
    int x;
    int y;
};
coordnts t[100005];
int dis[100005], ST[500005];
void build(int id, int l, int r)
{
    if(l==r)
        ST[id]=dis[l];
    else
    {
        int mid=(l+r)/2;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        ST[id]=ST[2*id]+ST[2*id+1];
    }
}
int result(int id, int l, int r, int x)
{
    if(x<l || x>r)
        return 0;
    if(x==r)
        return ST[id];
    int mid=(l+r)/2;

}
int main()
{
    freopen("DIST.INP","r",stdin);
    freopen("DIST.OUT","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>t[i].x>>t[i].y;
    int m=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            dis[m]=min(abs(t[i].x-t[j].x),abs(t[i].y-t[j].y));
            m++;
        }
    }
    sort(dis+1,dis+m);
    for(int i=1;i<=m-1;i++)
        cout<<dis[i]<<" ";
    /*build(1,1,m-1);
    cout<<result(1,1,m-1,k);*/
}
