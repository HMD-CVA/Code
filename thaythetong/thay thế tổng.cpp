#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
int a[10000];

void nhap()
{

    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
}
void process()
{
    priority_queue< int, vector<int>, greater<int> > x;
    ll s=0;
    for(ll i=1;i<=n;i++)
    {
        s+=a[i];
        x.push(a[i]);
    }
    cout<<s<<" ";
    ll y=0;
    ll u,v;
    while(x.size()>1)
    {
        u=x.top();
        x.pop();
        v=x.top();
        x.pop();
        y+=u+v;
        x.push(u+v);
    }
    cout<<y;
}
int main()
{
    nhap();
    process();
}
