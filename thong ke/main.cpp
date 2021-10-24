#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n;
ll a[1000][1000];
double b[100];
ll c,d,e;
void doc()
{
    cin>>n;
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=4; j++)
        {
            cin>>a[i][j];
        }
    }
}
void process()
{
    int h=1;
    ll visit[1000];
    double x;
    for(ll j=1; j<=4; j++)
    {
        c = 0;
        for(ll i=1; i<=n; i++)
        {
            c+=a[i][j];
        }
        x = (double)c/n;
        b[h] = x;
        h++;
    }
    for(ll j=1; j<=4; j++)
    {
        d = n;
        for(ll i=1; i<=n; i++)
        {
            if(a[i][j] <= b[j] || visit[i]==1)
            {
                d--;
                visit[i]=1;
            }
        }
        b[j] = d;
        //cout<<d<<" ";
    }
    sort(b+1,b+4+1);
    cout<<b[1];
}
int main()
{
    doc();
    process();
}
