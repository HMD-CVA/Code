#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a,b,x;
void nhap()
{
    cin>>a>>b>>x;
}
void process()
{
    ll i=a,c=b,j=0,e=0,d=0,s;
    while(i<=b)
    {
        if(i%x==0)
        {
            j=i;
            break;
        }
        i+=(x-(i%x));
    }
    while(c>=a)
    {
        if(c%x==0)
        {
            e=c;
            break;
        }
        c=c-(c%x);
    }
    s=(e-j)/x+1;
    //cout<<j<<" "<<e<<endl;
    cout<<s;
}
int main()
{
    nhap();
    process();
}
