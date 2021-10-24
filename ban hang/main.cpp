#include <bits/stdc++.h>
#define ll long long
#define ft(i,x,y) for(i=x;i<=y;i++)
#define fl(i,x,y) for(i=x;i>=y;i--)
using namespace std;

ifstream f1("bh.inp");
ofstream f2("bh.out");
ll m,n;
ll a[100000],b[100000],visit[100000];
ll i,j,x,y;
void nhap()
{
    f1>>m;
    ft(i,1,m)
    {
        f1>>b[i];
    }
    f1>>n;
    ft(i,1,n)
    {
        f1>>a[i];
    }
}
void process()
{
    stack<ll> s;
    ft(i,1,n)
    {
        ll y=a[i];
        ll e=0;
        while(visit[a[i]]==1)
        {
            a[i]+=y;
        }
         s.push(a[i]);
         visit[a[i]]=1;
         e++;
         while(e<=a[i])
        {
            x=s.top()+y;
            if(visit[x]==1)
            {
                x+=y;
            }
            s.push(x);
            visit[x]=1;
            e++;
        }
    }
    ll d=0;
    while(!s.empty() && d<=m)
    {
        if(binary_search(b+1,b+m,s.top()))
            {
                d++;
            }
        s.pop();
    }
    f2<<d;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    nhap();
    process();
}
