#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1006][1006],f[1006][1006],maxx=INT_MIN;
void Nhap()
{
    cin >> n >> k;
    for (long long i=1;i<=n;i++)
        for (long long j=1;j<=n;j++)
            cin >> a[i][j];
}
void Xl()
{
    long long res=0;
    for(long long i=1;i<=n;i++)
    {
        f[1][i]=f[1][i-1]+a[1][i];
        f[i][1]=f[i-1][1]+a[i][1];
    }
    for(long long i=2;i<=n;i++)
    {
        for (long long j=2;j<=n;j++)
        {
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
        }
    }
    for (long long i=k;i<=n;i++)
    {
        for (long long j=k;j<=n;j++)
        {
            long long p=f[i][j]-f[i-k][j]-f[i][j-k]+f[i-k][j-k];
            res=max(res,p);
        }
    }
    cout << res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.inp","r",stdin);
    Nhap();
    Xl();
}
