#include <bits/stdc++.h>
#define ll long long
#define MAX 300000
#define oo 1000000007

using namespace std;

ll n, k;
ll a[MAX], f[MAX];
ll sum = 0, kq = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    f[0] = 1;
    f[1] = 1;
    for(ll i = 2; i <= 2*k+1; i ++)
        f[i] = (f[i-1] + f[i-2])%oo;
    kq = (f[2*k]*n)%oo;
    cout<<kq;

}
