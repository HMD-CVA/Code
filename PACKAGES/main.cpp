#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.inp","r",stdin);
    unsigned long long n,p,q,u,v,cp,k;
    cin >> n >> p >> q >> u >> v;
    if (q*u<v*p)
    {
        swap(q,v);
        swap(p,u);
    }
    k=n/u;
    cp=k*v;;
    if (n%u>0) cp+=v;
    for (int i=k;i>=0;i--)
    {
        cp=min(cp,i*v+((n-i*u)/p)*q+min(q,(n-i*u)%p));
    }
    cout << cp;
}
