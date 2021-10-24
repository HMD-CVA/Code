#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,p;
void nhap()
{
    cin>>n>>p;
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
    ll d=0;
    for(ll i=1;i<=n;i++)
    {
        if(ucln(i,n)==p)
            d++;
    }
    cout<<d;
}
int main()
{
    nhap();
    process();
}
