#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll n,k;
int a[100000];
void nhap()
{
    cin>>k>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
}
/*void process()
{
    ll d=2,h=1,e=0;
    int b[100000];
    sort(a+1,a+n+1);
    for(ll i=2;i<=n;i++)
    {
        if(a[i+1]-a[i]==1)
        {
            d++;
            for(ll j=i+1;j<=n;j++)
            {
                if(a[j+1]-a[j]==1)
                {
                    d++;
                }
                else if(a[j+1]-a[j]==2 && e==0)
                {
                    d++;
                    e++;
                }
                else
                    continue;
            }
            b[h]=d;
            h++;
            d=2;
            e=0;
        }
        if(a[i+1]-a[i]==2)
        {
            d++;
            for(ll j=i+1;j<=n;j++)
            {
                if(a[j+1]-a[j]==1)
                {
                    d++;
                }
                else
                    continue;
            }
            b[h]=d;
            h++;
            d=2;
        }
    }
    sort(b+1,b+h);
    cout<<b[h-1];
}*/
void process()
{
    int b[100000];
    ll d,e,h=1;
    sort(a+1,a+n+1);
    for(ll i=2;i<n;i++)
    {
        d=1;
        e=0;
        for(ll j=i+1;j<=n;j++)
        {
            if(a[j]-a[i]==1)
            {
                d++;
            }
            else if(a[j]-a[i]==2 && e==0)
            {
                d+=2;
            }
            else
                continue;
        }
        b[h]=d;
        h++;
    }
    sort(b+1,b+h);
    cout<<b[h-1]+1;
}
int main()
{
    nhap();
    process();
}
