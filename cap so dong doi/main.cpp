#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n;
ll d = 2;
void doc()
{
    cin>>n;
}
void process()
{
    if(n%2 == 0)
    {
        d=5;
    }
        for(ll i=3; i<n/2; i++)
        {
            ll e=i;
            ll f=n-i;
            if(f%e == 0)
                d+=2;
        }
    cout<<d;
}
int main()
{
    doc();
    process();
}
