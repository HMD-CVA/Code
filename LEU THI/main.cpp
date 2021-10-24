#include <bits/stdc++.h>
#define ll long long

using namespace std;
ifstream f1("LTHI.INP");
ofstream f2("LTHI.OUT");
int n,k;
int a[10000];
void doc()
{
    cin>>n>>k;
}
int gt(int n)
{
    a[0]=1;
    a[1]=1;
    for(int i=2;i<=n;i++)
    {
        a[i]=i*a[i-1];
    }
    return a[n];
}
void process()
{
    a[1]=0;
    a[2]=1;
    for(int i=1;i<=n-k;i++)
    {
        a[i]=a[i-1]*(i-1);
    }
    int x;
    x=gt(n)/(gt(k)*gt(n-k));
    cout<<a[n-k]*x;
}
int main()
{
    doc();
    process();
}
