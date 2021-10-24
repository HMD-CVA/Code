#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n,d;
int a[100005];
void nhap()
{
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]%2==0)
            d++;
    }
}
void process()
{
    if(d<n-d)
    {
        for(ll i=1;i<=n;i++)
        {
            if(a[i]%2==0)
            {
                cout<<a[i]<<" ";
            }
        }
    }
    else
    {
        for(ll i=1;i<=n;i++)
        {
            if(a[i]%2==1)
            {
                cout<<a[i]<<" ";
            }
        }
    }
}
int main()
{
    nhap();
    process();
}
