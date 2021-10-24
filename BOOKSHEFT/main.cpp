#include<bits/stdc++.h>
using namespace std;
long long n,l,w[100005]={0},h[100005]={0},dp[100005]={0};
void enter()
{
    cin>>n>>l;
    for(long long i=1;i<=n;i++)
        cin>>h[i]>>w[i];
}
void process()
{
    for(long long i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+h[i];
        long long j=i;long long sum=w[i];long long mx=h[i];
        while(sum+w[j-1]<=l&&j>1)
        {
            sum+=w[j-1];mx=max(mx,h[j-1]);
            dp[i]=min(dp[i],dp[j-2]+mx);
            j--;
        }
    }
    //for(long long i=1;i<=n;i++) cout<<dp[i]<<" ";
    cout<<dp[n];
}
int main()
{
    enter();
    process();
}

