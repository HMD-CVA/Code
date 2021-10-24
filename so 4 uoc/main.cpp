#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
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
void process()
{
    int b[10000];
    ll h=1,e=0;
    for(ll i=1;i<=n/2;i++)
    {
        if(n%i==0)
        {
            b[h]=i;
            h++;
        }
    }
    b[h]=n;
    for(ll i=1;i<=h;i++)
    {
        if(demuoc(b[i])==4)
            e++;
    }
    cout<<e;
}
int main()
{
    nhap();
    process();
}
