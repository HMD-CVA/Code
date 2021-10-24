#include <bits/stdc++.h>
using namespace std;
int n,d=0,x;
int a[1001],k[1001];
void doc()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
}
bool TArray(int k, int a[],int n)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]*2==k)
            return true;
    }
    return false;
}
void bt(int i)
{

}
int main()
{
    freopen("DT.inp","r",stdin);
    freopen("DT.out","w",stdout);
    doc();
    bt(1);
    cout<<d;
}
