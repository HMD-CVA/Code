#include <bits/stdc++.h>
using namespace std;
int GCD(int a,int b)
{
    while(a!=b)
    {
        if(a>b)
            a=a-b;
        else if(a<b)
            b=b-a;
    }
    return a;
}
int mir(int n)
{
    int tmp;
    int res=0;
    while(n>0)
    {
        tmp=n%10;
        res=res*10+tmp;
        n=n/10;
    }
    return res;
}
int main()
{
    freopen("FRIENDLYNUM.inp","r",stdin);
    freopen("FRIENDLYNUM.out","w",stdout);
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++)
    {
        if(GCD(i,mir(i))==1)
            cout<<i<<" ";
    }
}
