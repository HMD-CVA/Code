#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1000][1000];
int pts[1000];
int x[1000],dem[1000];
void doc()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            cin>>a[i][j];
        }
        cin>>pts[i];
    }
}
void ghi()
{
    for(int i=1;i<=k;i++)
        cout<<x[i]<<" ";
    cout<<endl;
}
void xuli()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(x[j]==a[i][j])
                dem[i]++;
        }
    }
    for(int i=1;i<=n;i++)
        {
            if(dem[i]!=pts[i])
                break;
        }
        ghi();
}
void BT(int z)
{
    for(int j=1;j<=9;j++)
    {
        x[z]=j;
        if(z==k)
            xuli();
        else
            BT(z+1);
    }
}
int main()
{
    freopen("XOSO.inp","r",stdin);
    freopen("XOSO.out","w",stdout);
    doc();
    BT(1);
}
