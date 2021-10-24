#include <bits/stdc++.h>
using namespace std;
int n,a[100000];
int b[1000][1000],dp[1000][1000];
void doc()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
		b[i][i] = a[i];
		dp[i][i] = 0;
    }

}
void xl()
{
	for(int i=1;i<=n;i++)
	{
		b[i][i+1]=a[i]+a[i+1];
		dp[i][i+1]=b[i][i+1];
	}
	for(int i=n;i>=1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int l=i;l<=j;l++)
            {
                if(dp[i][l]+b[i][l]+dp[l+1][j]+b[l+1][j]<dp[i][j])
                    {
                        dp[i][j]=dp[i][l]+b[i][l]+dp[l+1][j]+b[l+1][j];
                        b[i][j]=b[i][l]+b[l + 1][j];
                    }
            }
        }
    }
	cout<<dp[1][n];
}
int main()
{
    doc();
    xl();
}


