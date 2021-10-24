#include <bits/stdc++.h>
#define st first
#define nd second
using namespace std;
int parent1[10005],parent2[10005],rank1[10005],rank2[10005];
int n,q,x,u,v;
typedef pair<int,int> ii;
queue <ii> qct,qdn;
int find_set1(int u)
{
    if(parent1[u]!=u)
        parent1[u]=find_set1(parent1[u]);
    return parent1[u];
}
int find_set2(int u)
{
    if(parent2[u]!=u)
        parent2[u]=find_set2(parent2[u]);
    return parent2[u];
}
void union_set1(int u, int v)
{
    u=find_set1(u);
    v=find_set1(v);
    if(u!=v)
    {
        if(rank1[u]==rank1[v])
            rank1[u]++;
        if(rank1[u]<rank1[v])
            parent1[u]=v;
        else
            parent1[v]=u;
    }
    else
        return;
}
void union_set2(int u, int v)
{
    u=find_set2(u);
    v=find_set2(v);
    if(u!=v)
    {
        if(rank2[u]==rank2[v])
            rank2[u]++;
        if(rank2[u]<rank2[v])
            parent2[u]=v;
        else
            parent2[v]=u;
    }
    else
        return;
}
bool balance()
{
    if(qct.size()>0)
    {
        while(!qct.empty())
        {
            int x=qct.front().st;
            int y=qct.front().nd;
            if(find_set2(x)==find_set2(y))
                qct.pop();
            else
                break;
        }
    }
    if(qdn.size()>0)
    {
        while(!qdn.empty())
        {
            int x=qdn.front().st;
            int y=qdn.front().nd;
            if(find_set1(x)==find_set1(y))
                qdn.pop();
            else
                break;
        }
    }
    if(qct.size()==0 && qdn.size()==0)
        return true;
    return false;
}
void doc()
{

    cin>>n>>q;
    for(int i=1;i<=n;i++)
        parent1[i]=parent2[i]=i;
    memset(rank1,1,sizeof(rank1));
    memset(rank2,1,sizeof(rank2));
    for(int i=1;i<=q;i++)
    {
        cin>>x>>u>>v;
        if(x==1)
        {
            qct.push(make_pair(u,v));
            union_set1(u,v);
        }
        else
        {
            qdn.push(make_pair(u,v));
            union_set2(u,v);
        }
        if(balance())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
int main()
{
    //freopen("BALANCED.INP","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    doc();
}
/**/
