#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll n,m;
int a[100000];
void process(ll n)
{
    for(ll i=1;i<=n;i++)
        a[i]=1;
    ll i=2;
    while(i<=n)
    {
        /*for(ll j=1;j<=n;j++)
        {
            if(j%i==0)
            {
                if(a[j]==1)
                {
                    a[j]=0;
                }
                if(a[j]==0)
                {
                    a[j]=1;
                }
            }*/
            /*cout<<endl<<i<<endl;
            for(int k=1;k<=n;k++)
            {
                cout<<a[k]<<" ";
            }*/
            if(n%i==0)
            {
                if(a[n]==1)
                {
                    a[n]=0;
                }
                else
                    a[n]=1;
            }
        i++;
    }
    cout<<a[n]<<endl;
}
int main()
{
    ll x;
    cin>>m;
    for(ll i=1;i<=m;i++)
    {
        cin>>x;
        process(x);
    }

}
