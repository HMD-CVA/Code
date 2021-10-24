#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000],dp[1000];
void doc()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
}
void xl()
{
    sort(a+1,a+n+1);
    int tam=a[1];
    int h=1;
    for(int i=2;i<=n;i++)
    {
        dp[h]=dp[h-1]+a[i];
        dp[h+1]=dp[h]+tam;
        h+=2;
    }
    cout<<dp[h-2];
}
int main()
{
    doc();
    xl();
}
