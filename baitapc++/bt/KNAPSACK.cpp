#include <bits/stdc++.h>
using namespace std;
int n,W,sum=0;
long long w[10000],v[10000];
long long dp[10000];
void doc()
{
    cin>>n>>W;
    for(long long i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
        sum=sum+v[i];
    }
}
void qhd()
{
	dp[0]=0;
    for(long long i=0;i<=n;i++)
        for(long long j=sum;j>=v[i];j--)
            dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
    for(long long i=sum;i>=0;i--)
    {
        if(dp[i]<=W)
        {   
			cout<<i;
        	exit(0);
        }
    }
}
int main()
{
    doc();
    qhd();
}
