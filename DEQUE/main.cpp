#include <bits/stdc++.h>

using namespace std;
int n;
long long a[100000001],dp[10000][10000];
void doc()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
}
void xl()
{
    dp[0][0]=0;
    for(int i=n;i>=1;i--)
    {
        for(int j=i;j<=n;j++)
        {
            if (a[i]==a[j])  dp[i][i]=a[i];
            dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }
    cout<<dp[1][n];
}
int main()
{
    doc();
    xl();
}
