#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,a,b,c,d;
int dp[100000],x[100000];
void nhap()
{
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>x[i];
    }

}
/*void process()
{
    ll s=0,e=0,f=0;
    for(ll i=1;i<=n;i++)
    {
        if(x[i]%4==0)
            a++;
        if(x[i]%4==1)
            b++;
        if(x[i]%4==2)
            c++;
        if(x[i]%4==3)
            d++;
    }
    if(c%2==0)
    {
        c=c/2;
    }
    else
    {
        e=c%2;
        c=c/2;
    }
    if(b>d)
    {
        s+=b;
        b=b-d;
        d=0;
    }
    else if(d==b)
    {
        s=b;
        b=d=0;
    }
    else
    {
        d=d-b;
        b=0;
        s+=d;
    }
    if(e>0 && b>2)
    {
        f=1;
        e=0;
        b-=2;
    }
    if(b%4==0)
        b/=4;
    else if(b<4)
        b=1;
    else
        b=b/4+1;
    cout<<a+b+c+d+s+e+f;
}*/
void process()
{
    ll s=0,e=0,f=0;
    s=d[4];
    if(d[3]>d[1])
        d[1]=0;
    else
        d[1]-=d[3];
    s+=d[3];
    s+=d[2]/2;
    if(d[2]%2==0)
        d[2]=0;
    else
    {
        d[2]=1;
        s++;
        if(d[1]>2)
            d[1]-=2;
        else
            d[1]=0;
    }
    if(d[1]%4==0)
        s+=d[1]/4;
    else
        s+=d[1]/4+1;
    cout<<s;

}
int main()
{
    nhap();
    process();
}
