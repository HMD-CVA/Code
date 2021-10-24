#include<bits/stdc++.h>
using namespace std;
long long n,a[1006][1006],f[1006][1006];
void Nhap()
{
    cin >> n;
    for (long long i=1;i<=n;i++)
        for (long long j=1;j<=n;j++)
        {
            cin >> a[i][j];
            f[i][j]=1;
        }
}
long long min1(long long a, long long b, long long c)
{
    a=min(a,b);
    return min(a,c);
}
void Xl()
{
    long long res=0;
    for(long long i=2;i<=n;i++)
        for (long long j=2;j<=n;j++)
        {
            if(a[i][j]==a[i-1][j-1] && a[i][j]==a[i-1][j] && a[i][j]==a[i][j-1]) f[i][j]=min1(f[i-1][j-1],f[i-1][j],f[i][j-1])+1;
            if(f[i][j]>res) res=f[i][j];
        }
    cout<<res*res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.inp","r",stdin);
    Nhap();
    Xl();
}
