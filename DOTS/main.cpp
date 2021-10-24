#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("DOTS.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long x,y,z,t,k,a,b;
    cin >> x >> y >> z >> t;
    a=z-x;
    b=t-y;
    k=abs(__gcd(a,b));
    cout << k+1;
}
