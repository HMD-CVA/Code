#include <bits/stdc++.h>
#define ifn 200005
using namespace std;
int n,q,type,u,v;
int par[ifn],rankk[ifn];
int find_set(int u)
{
    if(par[u]==u)
        return u;
    par[u]=find_set(par[u]);
    return par[u];
}
void union_set(int u, int v)
{
    int r1=find_set(u);
    int r2=find_set(v);
    if(r1==r2)
        return;
    if(rankk[r1]==rankk[r2])
        rankk[r1]++;
    if(rankk[r1]<rankk[r2])
        par[r1]=r2;
    else
        par[r2]=r1;
}
void process()
{
    memset(rankk,1,sizeof(rankk));
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        par[i]=i;
    for(int i=1;i<=q;i++)
    {
        cin>>type>>u>>v;
        if(type==1)
            union_set(u,v);
        else if(type==2)
        {
            while(u<=v)
            {
                union_set(u,v);
                u++;
            }
        }
        else if(type==3)
        {
            if(find_set(u)==find_set(v))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
}
int main()
{
    //freopen("RESTRUCT.INP","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    process();
}
