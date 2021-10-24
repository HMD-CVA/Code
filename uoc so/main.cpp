#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll m,p,k,u,v;
ll n = 1;
void doc()
{
    cin>>m;
    for(ll i=1; i<=m; i++)
    {
        cin>>p>>k;
        n = n*pow(p,k);
    }
}

int main()
{
    doc();
    cout<<n<<endl;
    for(int i=1; i<=3; i++)
    {
        cin>>u>>v;
        ll d=0;
        for(ll j=u; j<=v; j++)
        {
            if(n%j == 0)
                d++;
        }
        cout<<d<<endl;
    }
}
