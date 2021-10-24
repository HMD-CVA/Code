#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,s=0,cl1,a[1000001],cl[1000001],dem=1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.inp","r",stdin);
    cin >> n >> m;
    for (ll i=1;i<=n;i++) cin >> a[i];
    for (ll i=1;i<=n;i++) cin >> cl[i];
    cl1=cl[1];
    for (ll i=1;i<=n;i++)
    {
        s+=a[i];
        if (cl1!=cl[i] || s>m)
        {
            dem++;
            cl1=cl[i];
            s=a[i];
        }
    }   
    cout << dem;
}