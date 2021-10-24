#include <bits/stdc++.h>

using namespace std;
int n,m;
int a[1000][1000],dp[1000][1000];
void doc()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
           cin>>a[i][j];
}
void xl()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==j)
                dp[i][j]=1;
            else
                {
                    int s=i*j;
                    for(int x=1;x<=i-1;x++)
                        s=min(s,dp[x][j]+dp[i-x][j]);
                    for(int x=1;x<=j-1;x++)
                        s=min(s,dp[i][x]+dp[i][j-x]);
                    dp[i][j]=s;
                }

        }
    }
    cout<<dp[n][m];
}
int main()
{
    doc();
    xl();
}
