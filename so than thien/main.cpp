#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n,m;
void nhap()
{
    cin>>n>>m;
}
ll sdn(ll n)
{
    ll x=0,y=0;
    while(n!=0)
    {
        y=n%10;
        n=n/10;
        x=x*10+y;
    }
    return x;
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
int main()
{
    nhap();
    ll d=0;
    for(ll i=n;i<=m;i++)
    {
        if(ucln(i,sdn(i))==1)
            d++;
    }
    cout<<d;
}
