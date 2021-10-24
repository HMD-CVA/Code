#include <bits/stdc++.h>
#define ifn 10005
using namespace std;
long long w[ifn],b[ifn],sw[ifn],sb[ifn],fz[ifn];
long long u,v;
vector <long long> vt[ifn];
long long dp[ifn];
int n,m,W;
void doc()
{
    cin>>n>>m>>W;
    for(int i=1;i<=n;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
}
int find_set(int u)
{
    if(fz[u]==u)
        return u;
    else
        fz[u]=find_set(fz[u]);
    return fz[u];
}
void process()
{
    for(int i=1;i<=n;i++)
        fz[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        fz[find_set(v)]=find_set(u);
    }
    for(int i=1;i<=n;i++)
    {
        sw[find_set(i)]+=w[i];
        sb[find_set(i)]+=b[i];
        vt[find_set(i)].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=W;j>=0;j--)
        {
            if(vt[i].size()>0)
            {
                for(int k=0;k<vt[i].size();k++)
                {
                    u=vt[i][k];
                    if(j>=w[u])
                    {
                        dp[j]=max(dp[j],dp[j-w[u]]+b[u]);
                        //vt[i].pop_back();
                    }
                }
            }
            if(j>=sw[i])
                dp[j]=max(dp[j],dp[j-sw[i]]+sb[i]);
        }
    }
    cout<<dp[W];
}
int main()
{
    //freopen("PARTY.INP","r",stdin);
    doc();
    process();
}
