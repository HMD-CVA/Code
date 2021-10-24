#include <bits/stdc++.h>

using namespace std;
ifstream f1("BRIDGE.inp");
ofstream f2("BRIDGE.out");
int n;
int a[1000],dp[1000];
void doc()
{
    f1>>n;
    for(int i=1;i<=n;i++)
        f1>>a[i];
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
    f2<<dp[h-2];
}
int main()
{
    doc();
    xl();
}
