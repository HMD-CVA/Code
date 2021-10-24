#include <bits/stdc++.h>
using namespace std;
int64_t res=0,minn=0,n,k;
int64_t s[1000001];
void xuli()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        s[i]=s[i-1]+k;
    }
    for(int i=1;i<=n;i++)
    {
        res=max(res,s[i]-minn);
        minn=min(minn,s[i]);
    }
    cout<<res;
}
int main()
{
    freopen("TONGMAX.INP","r",stdin);
    freopen("TONGMAX.OUT","w",stdout);
    xuli();
}
