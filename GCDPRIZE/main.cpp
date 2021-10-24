#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[1000];
void doc()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
}
int GCD(int a,int b)
{
    while(a!=b)
    {
        if(a>b)
            a=a-b;
        else if(b>a)
            b=b-a;
    }
    return a;
}
void xuli()
{
    k=GCD(a[1],a[2]);
    for(int i=3;i<=n;i++)
        k=GCD(k,a[i]);
    cout<<k;
}
int main()
{
    freopen("GCDPRIZE.inp","r",stdin);
    freopen("GCDPRIZE.out","w",stdout);
    doc();
    xuli();
}
