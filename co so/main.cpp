#include <bits/stdc++.h>
#define ll long long
#define ft(i,x,y) for(i=x;i<=y;i++)
#define fl(i,x,y) for(i=x;i>=y;i--)
using namespace std;

ll s,m,n;
ll a[100000],b[100000];
ll i,j,x,y;
void nhap()
{
    cin>>s>>m>>n;
}
ll coso(ll s, ll x)
{
    ll sum=0;
    while(s>0)
    {
    	j=s%x;
    	sum+=j;
        s=s/x;
	}
	return sum;
}
void process()
{
    bool kt=false;
    ll T=s;
    if(n==0)
    {
        cout<<"0";
    }
    else
    {
        while(kt==false)
    {
        if(coso(T,m)-coso(T,n)==0)
        {
            kt=true;
            cout<<T;
            break;
        }
        else
        {
            T++;
        }
    }
    }

}
int main()
{
   nhap();
   process();
}
