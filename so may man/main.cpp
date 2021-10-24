#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll n,l,r;
void nhap()
{
    cin>>n;
}
ll demuoc(ll a)
{
    ll d=0;
    for(ll i=1;i<=a/2;i++)
    {
        if(a%i==0)
        {
            d++;
        }
    }
    return d+1;
}
void process(ll l,ll r)
{
    ll d=0;
    for(ll i=l;i<=r;i++)
    {
        if(demuoc(i)==4)
            d++;
    }
    cout<<d;
}
int main()
{
   nhap();
   for(ll i=1;i<=n;i++)
   {
       cin>>l>>r;
       process(l,r);
   }
}
