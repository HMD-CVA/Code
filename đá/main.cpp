#include <bits/stdc++.h>

using namespace std;
int n,k;
int a[100000],dp[100000];
void doc()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
}
void xl()
{
    for(int i=1;i<=n;i++)
        dp[i]=0;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>=a[j] && dp[i-a[j]]==0)
                dp[i]=1;
        }
    }
    if(dp[k]==1)
        cout<<"First";
    else
        cout<<"Second";
}
int main()
{
    doc();
    xl();
}
