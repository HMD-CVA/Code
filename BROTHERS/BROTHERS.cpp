#include <bits/stdc++.h>

using namespace std;
ifstream f1("brothers.inp");
ofstream f2("brothers.out");
int n,m;
int a[10000][10000],f[10000][10000];
void doc()
{
    f1>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            f1>>a[i][j];
}
void xuli()
{
    int s1,s2,kt[10000][10000];
    for (int i=1;i<=n;i++)
    {
        f[0][i]=0;
        f[i][0]=0;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
             f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
    s1=f[n][m];
    int i=n,j=m;
    while (i>0 && j>0)
    {
        if (f[i][j]==f[i-1][j]+a[i][j])
            {
                kt[i-1][j]=1;
                i--;
            }
        else
            {
                kt[i][j-1]=1;
                j--;
            }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (kt[i-1][j]==1) f[i][j]=f[i][j-1]+a[i][j];
            else if (kt[i][j-1]==1) f[i][j]=f[i-1][j]+a[i][j];
            else f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
        }
    }

    s2=f[n-1][m];
    f2<<s1+s2;
}
int main()
{
    doc();
    xuli();
}
