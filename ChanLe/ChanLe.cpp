#include<bits/stdc++.h>
using namespace std;
long long n,a[100001],dem=0,s=0,maxx=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.inp","r",stdin);
    cin >> n;
    for (long long i=1;i<=n;i++)
    {
        cin >> a[i];
        if (a[i]%2!=0) dem++;
    }
    if (dem==n) 
    {
        cout << "-1";
        return 0;
    }
    for (long long i=1;i<=n-1;i++)
    {
        s=a[i]+a[i+1];
        if (s%2!=0) maxx=max(s,maxx);
    }
    cout << maxx;
}