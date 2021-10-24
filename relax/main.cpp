#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n,u;
void process(ll n)
{
    ll sum;
    sum = (n+1)*n/2;
    if(n%2 != 0)
        sum = sum*(-1);
    cout<<sum<<endl;
}
int main()
{
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>u;
        process(u);
    }
}
