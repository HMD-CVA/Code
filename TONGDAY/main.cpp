#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int n,maxx=0,k;
void doc()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
}
int arrsum(int l, int r)
{
    int64_t sum=0;
    for(int i=l;i<=r;i++)
        sum+=a[i];
    return sum;
}
int main()
{
    freopen("TONGDAY.inp","r",stdin);
    freopen("TONGDAY.out","w",stdout);
    doc();
    for(int l=1;l<=n;l++)
    {
        for(int r=l+1;r<=n;r++)
        {
            k=arrsum(l,r);
            if(k>=maxx)
                maxx=k;
        }
    }
    cout<<maxx;
}
