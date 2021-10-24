#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n;
int a[100000];
void nhap()
{
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
}
ll ucln(ll n, ll m)
{
    ll temp;
    if(n==0 || m==0)
        return n+m;
    else
    {
        while(n*m!=0)
        {
            if(n>m)
                n-=m;
            else
                m-=n;
        }
        return n;
    }
}
void process()
{
    ll x=a[1];
    for(ll i=2;i<=n;i++)
    {
        x=ucln(x,a[i]);
    }
    cout<<x;
}
int main()
{
    nhap();
    process();
}
