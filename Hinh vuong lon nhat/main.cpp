#include <bits/stdc++.h>
#define ll long long

using namespace std;
ifstream f1("MSQUARE.INP");
ofstream f2("MSQUARE.OUT");
int n;
int a[1000][1000];
int dp[1000][1000];
void doc()
{
    f1>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            f1>>a[i][j];
        }
    }
}
void process()
{
    int maxx=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==a[i-1][j] && a[i][j]==a[i][j-1] && a[i][j]==a[i-1][j-1])
                dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
            else
                dp[i][j]=1;
            maxx=max(maxx,dp[i][j]);
        }
    }
    f2<<maxx*maxx;
}
int main()
{
    doc();
    process();
}
