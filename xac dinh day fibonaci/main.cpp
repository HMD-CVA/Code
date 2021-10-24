#include <bits/stdc++.h>
#define ll long long
#define ft(i,x,y) for(i=x;i<=y;i++)
#define fl(i,x,y) for(i=x;i>=y;i--)
using namespace std;

ifstream f1("fi.inp");
ofstream f2("fi.out");
ll n;
ll a[100000],b[100000],c[100000];
ll i,j,x,y;
void nhap()
{
    f1>>n;
    ft(i,1,n)
    {
        f1>>a[i];
    }
}
void process()
{
    queue<ll> x;
    ll d=0,e=0;
    b[1]=a[1];
    b[2]=a[2];
    i=3;
    while (i<=n)
    {
    	b[i]=b[i-1]+b[i-2];
    	i++;
	}
	ft(i,1,n)
	{
	    x.push(b[i]);
	}
	j=1;
	while(j<=n)
    {
        if(a[j]==x.front())
        {
            x.pop();
            e++;
        }
        else
        {
            d++;

        }
        j++;
    }
	f2<<d;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();cout.tie();
    nhap();
    process();
}
