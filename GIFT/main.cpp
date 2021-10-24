#include <bits/stdc++.h>
using namespace std;
int n,a[100],dp[100][3];
void nhap()
{
    freopen("in.inp","r",stdin);
    cin >> n ;
    for (int i=1;i<=n;i++) cin >> a[i];
}
int main()
{
    nhap();
    dp[1][1]=a[1];
    dp[2][1]=a[1];
    dp[3][1]=a[1]+a[3];
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=3;i++)
        {
            if (i%2==0)
            {
                dp[i][j]=max(dp[i][j],dp[i][n-2]);
            }
             else dp[i][j]=max(dp[i][j],dp[i][n-1]);
        }

    }

}
