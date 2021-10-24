#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll n,t,x;
void process( ll x)
{
    ll a=trunc(sqrt(x));
    ll b=a*a+1;
    ll i=1;
    while(b<x)
    {
        b=(a+i)*(a+i)+1;
        i++;
    }
    cout<<b<<endl;
}
int main()
{
    cin>>n>>t;
    for(ll i=1;i<=t;i++)
    {
        cin>>x;
        process(x);
    }
}
