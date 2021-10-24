#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n;
int a[100000],kt[100000];

void nhap()
{
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        kt[a[i]]++;
    }
}
void process()
{
    ll d=0;
    for(ll i=1;i<=n;i++)
    {
        if(kt[i]>0)
        {
            d+=kt[i]/i;
        }
    }
    cout<<d;
}
int main()
{
    nhap();
    process();
}
