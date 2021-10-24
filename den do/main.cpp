#include <bits/stdc++.h>

using namespace std;

long long n,m,p[10000],u,v;
void nhap()
{
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>p[i];
    }

}
void process()
{
    for(long long i=1;i<=n;i++)
    {
        cout<<p[i]<<endl;
    }
}
int main()
{
    nhap();
    process();
}
