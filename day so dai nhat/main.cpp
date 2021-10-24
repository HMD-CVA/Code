#include <bits/stdc++.h>
#define ll long long

using namespace std;
ifstream f1("DAYSO.INP");
ofstream f2("DAYSO.OUT");

ll n,dem=0;
int a[100000];
void nhap()
{
    cin>>n;
    for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]<=0)
                dem++;
        }
}
void process()
{
    int b[100000];
    ll i=1;
    ll x,y;
    while(i<=n)
    {
        if(a[i]>=0)
        {
            x=i;
            break;
        }
        i++;
    }
    for(ll j=x;j<=n;j++)
    {
        b[j]=b[j-1]+a[j];
    }
    ll temp=INT_MIN;
    for(ll j=1;j<=n;j++)
    {
        if(temp<b[j])
        {
            temp=b[j];
            y=j;
        }
    }
    cout<<x<<" "<<y<<endl<<temp;
}
void process1()
{
    ll b,c;
    int dp[100000];
    ll temp=INT_MIN;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i+1;j<=n;j++)
        {
            if(dp[j]-dp[i-1]>temp)
            {
                temp=dp[j]-dp[i-1];
                b=i;
                c=j;
            }
        }
    }
    /*for(ll i=1;i<=n;i++)
    {
        if(temp<a[i])
        {
            temp=a[i];
            b=i;
            c=i;
        }
    }*/
    cout<<b<<" "<<c<<endl<<temp;
}
int main()
{
    nhap();
    if(dem==n)
    {
        process1();
    }
    else
    {
        process();
    }
}
