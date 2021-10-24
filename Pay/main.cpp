#include <bits/stdc++.h>
using namespace std;
long long n,a[100001],dp[100001],t[100001];
void nhap()
{
    //freopen("pay.inp","r",stdin);
    cin >> n;
    for (long long i=1;i<=n;i++) cin >> a[i];
}
void tong()
{
    t[0]=0;
    for (long long i=1;i<=n;i++) t[i]=t[i-1]+a[i];
}
void qhd()
{
    for (long long i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+a[i];
        if (i>=10)
        {
            long long k=INT_MAX;
            for (long long j=i-9;j<=i;j++)
            {
                k=min(k,a[j]);
            }
            dp[i]=min(dp[i],dp[i-10]+(t[i]-t[i-10]-k));
        }
    }
}
int main()
{
    nhap();
    tong();
    qhd();
    cout << dp[n];
}
