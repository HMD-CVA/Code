#include <bits/stdc++.h>
using namespace std;
int a[30001];
int64_t hp=0,k=0,n;
void doc()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        k=k+a[i];
    }
}
void process()
{
    for(int i=1;i<=n;i++)
    {
        k-=a[i];
        hp+=a[i]*k;
    }
    cout<<hp;
}
int main()
{
    freopen("HPPT.inp","r",stdin);
    freopen("HPPT.out","w",stdout);
    doc();
    process();
}
