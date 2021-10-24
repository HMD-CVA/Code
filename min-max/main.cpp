#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n,x;
int a[100000];
void nhap()
{
    cin>>n>>x;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
}
bool xl(ll l,ll r,ll x,int a[10000])
{
    ll temp=INT_MIN;
    ll tenp=INT_MAX;
    for(ll i=l;i<=r;i++)
    {
        if(a[i]>temp)
        {
            temp=a[i];
        }
        if(a[i]<tenp)
        {
            tenp=a[i];
        }
    }
    if((temp-tenp)==x)
        return true;
    else
        return false;
}
void process()
{
    ll d=0;
    for(ll i=1;i<n;i++)
    {
        for(ll j=i+1;j<=n;j++)
        {
            if(xl(i,j,x,a))
            {
                d++;
            }
        }
    }
    cout<<d;
}
int main()
{
    nhap();
    process();
}
