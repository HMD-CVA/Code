#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,a,b,c=0;
void nhap()
{
    cin>>n>>m;
}
void process()
{
    ll e=0,f=0;
    ll d=0,s=0,x=0;
	x=(m-n)+1;
	s=(m+n)*x/2;

    a=n;
    b=m;
    while(a<=m)
    {
        if(a%13==0)
        {
            e=a;
            break;
        }
        a+=13-(a%13);
    }
    while(b>=n)
    {
        if(b%13==0)
        {
            f=b;
             break;
        }
        b=b-(b%13);
    }
    c=(f-e)/13+1;
    d=(f+e)*c/2;
    cout<<s-d;
}
int main()
{
    nhap();
    process();
}
