#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n,s;
int a[100000];
int u[100000],v[100000];
void nhap()
{
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>s)
            s=a[i];
    }
}
bool snt(ll x)
{
    bool kt=true;
    if(x<2) kt=false;
    for(ll i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
            kt=false;
    }
    return kt;
}
void process()
{
    ll d=0,k=1;
    while(d<s)
    {

        if(snt(3*k+1) && snt(3*k+7))
            {
                d++;
                u[d]=3*k+1;
                v[d]=3*k+7;
            }
        if(snt(3*k+2) && snt(3*k+8))
            {
                d++;
                u[d]=3*k+2;
                v[d]=3*k+8;
            }
            k++;
    }
}
int main()
{
    nhap();
    process();
    for(ll i=1;i<=n;i++)
    {
        cout<<u[a[i]]<<" "<<v[a[i]]<<endl;
    }
}
