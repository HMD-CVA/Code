#include <bits/stdc++.h>
using namespace std;
int n,m,b[1006],a[1006][1006],hd[6],td[6],dem=0,maxx=-1;
bool vis[1006][1006];
void kt1()
{
    hd[1]=-1;
    td[1]=0;
    hd[2]=1;
    td[2]=0;
    hd[3]=0;
    td[3]=-1;
    hd[4]=0;
    td[4]=1;
}
void nhap()
{
    //freopen("in.inp","r",stdin);
    cin >> m >> n;
    for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) cin >> a[i][j];
}
void dfs(int u, int v,int d)
{
    vis[u][v]=true;
    for (int i=1;i<=4;i++)
    {
        if (1<=u+hd[i] && u+hd[i]<=m && v+td[i]<=n && v+td[i]>=1 && vis[u+hd[i]][v+td[i]]==false && a[u][v]==a[u+hd[i]][v+td[i]])
        {
            b[d]++;
            dfs(u+hd[i],v+td[i],d);
        }
    }
}
int main()
{
    nhap();
    kt1();
    memset(vis,false,sizeof vis);
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (vis[i][j]==false)
            {
                dem++;
                b[dem]=1;
                dfs(i,j,dem);
            }
        }
    }
    cout << dem << endl;
    for (int i=1;i<=dem;i++)
    maxx=max(maxx,b[i]);
    cout << maxx;
}
