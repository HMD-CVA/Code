#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,k;
int a[100000];
void doc()
{
    cin>>n>>k;
    for(ll i=1;i<=k;i++)
        cin>>a[i];
}
void process()
{
    int dp[100000];
    for(ll i=1;i<=n;i++)
        dp[i]=0;
    dp[0]=1;
    for(ll i=1;i<=k;i++)
    {
        for(ll j=a[i];j<=n;j++)
        {
            dp[j]+=dp[j-a[i]];
        }
    }
    cout<<dp[n];
}
int main()
{
    doc();
    process();
}
