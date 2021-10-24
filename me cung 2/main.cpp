#include <bits/stdc++.h>
using namespace std;
int a[1000][1000],n,m,d,tam[1000000],b[1000000],dp[1000000],xl[1000];
bool kt1[1000][1000];
void doc()
{
    cin>>n>>m;
    int u,v,c;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>c;
        kt1[u][v]=true;
        kt1[v][u]=true;
        a[u][v]=c;
        a[v][u]=c;
        xl[u]++;
        xl[v]++;
    }
}
bool kt(int k)
{
    if (d!=m+1) return false;
    for(int i=1;i<=n;i++)
        if (xl[i]==1) return false;
    int sum=0;
    for(int i=k;i<d;i++)
    {
        sum+=a[tam[i]][tam[i+1]];
        if (sum<0) return false;
    }
    for(int i=1;i<k;i++)
    {
        sum+=a[tam[i]][tam[i+1]];
        if (sum<0) return false;
    }
    return true;
}
void xuli()
{
    int u;
    int st=1;
    b[1]=1;
    while (st)
    {
        u=b[st];
        for(int v=1;v<=n;v++)
        {
            if (kt1[u][v])
            {
                kt1[u][v]=false;
                kt1[v][u]=false;
                st++;
                b[st]=v;
                break;
            }
        }
        if (u==b[st])
        {
            d++;
            tam[d]=u;
            st--;
        }
    }
    int minn=1000000000,bd;
    dp[1]=0;
    for(int i=2;i<=d;i++)
    {
        dp[i]=dp[i-1]+a[tam[i]][tam[i-1]];
        if (dp[i]<minn)
        {
            minn=dp[i];
            bd=i;
        }
    }
    if (!kt(bd)) cout << "-1";
    else
    {
        for(int i=bd;i<=d;i++) cout << tam[i] << " ";
        for(int i=2;i<=bd;i++) cout << tam[i] << " ";
    }
}
int main()
{
    doc();
    xuli();
}
