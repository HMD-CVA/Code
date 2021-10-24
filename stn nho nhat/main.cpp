#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n;
int a[100000],kt[100000];
priority_queue<ll> s;
void nhap()
{
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        kt[a[i]]=1;
        s.push(a[i]);
    }
}
void process()
{
    for(ll i=0;i<=s.top()+1;i++)
    {
        if(kt[i]==0)
        {
            cout<<i;
            break;
        }
    }
}
int main()
{
    nhap();
    process();
}
