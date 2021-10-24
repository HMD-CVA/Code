#include <bits/stdc++.h>
#define ll long long

using namespace std;
ifstream f1("NUMORDER.INP");
ofstream f2("NUMORDER.OUT");
ll a[10000][10000];
ll m,n,k;
void doc()
{
    f1>>m>>n>>k;
}
void process()
{
    for(ll i=1;i<=m;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            a[i][j]=i*i+j*j;
        }
    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
