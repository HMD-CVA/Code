#include <bits/stdc++.h>
#define ll long long

using namespace std;
ifstream f1("TONGMAX.INP");
ofstream f2("TONGMAX.OUT");
ll n,e=0;
ll a[100000];
void doc()
{
    f1>>n;
    for(ll i=1; i<=n; i++)
    {
        f1>>a[i];
    }
}
void process()
{
        ll s=0,kq=0;
        ll b[100000];
        ll h=1;
        for(ll i=1; i<=n; i++)
        {
            s=max(a[i],s+a[i]);
            kq=max(kq,s);
        }
        f2<<kq;

}
int main()
{
    doc();
    process();
}
