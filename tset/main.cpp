#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    ll d=0;
    for(ll i=1;i<=(n-1)/2;i++)
        d++;
    cout<<d;
}
