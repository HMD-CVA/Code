#include <bits/sydc++.h>
using namespace std;
struct node
{
    int val;
    int lazy;
};
node STL[10000];
// day lazy
void pushdwn(int id)
{
    STL[2*id].lazy+=STL[id].lazy;
    STL[2*id].val+=STL[id].lazy;
    STL[2*id+1].lazy+=STL[id].lazy;
    STL[2*id+1].val+=STL[id].lazy;
    STL[id].lazy=0;
}
//tao cay
void cre(int id, int l, int r, int u, int v, int x)
{
    if(l>v || r<u)
        return;
    if(u<=l && r<=v)
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
// get max
int getMx(int id, int l, int r, int u, int v);
{
    if(l>v || r<u)
        return INT_MIN;
    if(u<=l && r<=v)
        return STL[id].val;
    int mid=(l+r)/2;
    pushdwn(id);
    return max(getMx(2*id,l,mid,u,v),getMx(2*id+1,mid+1,r,u,v));
}
int main()
{

}
