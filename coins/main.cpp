#include<bits/stdc++.h>
using namespace std;
int n;
double p[3000];
double dp[3000][3000];
void doc()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i];

}
void xl()
{
    double sum=0;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
        dp[i][0]=dp[i-1][0]*(1-p[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=dp[i-1][j-1]*p[i]+dp[i-1][j]*(1-p[i]);
        }
    }
    for(int i=(n/2)+1;i<=n;i++)
        sum+=dp[n][i];
    cout<<setprecision(10)<<sum<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    doc();
    xl();
}
