#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a;
struct vec
{
    ll x;
    ll y;
};
vec b[10000],c[10000];
void nhap()
{
    cin>>a;
    for(ll i=1;i<=a;i++)
    {
        cin>>b[i].x>>b[i].y;
    }
}
void process()
{
    ll d=0;
    ll h=1;
    for(ll i=1;i<a;i++)
    {
        for(ll j=i+1;j<=a;j++)
        {
            c[h].x=b[i].x-b[j].x;
            c[h].y=b[i].y-b[j].y;
            h++;
        }
    }
    for(ll i=1;i<h-1;i++)
    {
        for(ll j=i+1;j<h;j++)
        {
            if((c[i].x*c[j].x + c[i].y*c[j].y)==0)
                d++;
        }
    }
    cout<<d;
}
int main()
{
    nhap();
    process();
}
