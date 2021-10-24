#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[10000001],s=0;
ll UCLN(ll a,ll b)
{
    if (b==0) return a;
    return UCLN(b,a%b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (ll i=1;i<=n;i++) cin >> a[i];
    for (ll i=1;i<n;i++)
    {
        s+=UCLN(a[i],a[i+1]);
    }
    cout << s;
}