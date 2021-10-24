#include <bits/stdc++.h>
using namespace std;
int n,l,r,lc,rc,k,maxx=0;
int a[100001];
void doc()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
}
void xuli()
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]%2!=0)
        {
            k++;
            l=i;
            while(a[i+1]%2!=0)
            {
                k++;
                i++;
            }
            r=i;
            if(k>maxx)
            {
                maxx=k;
                lc=l;
                rc=r;
            }
            k=0;
        }
    }
    cout<<maxx<<endl;
    for(int i=lc;i<=rc;i++)
        cout<<a[i]<<" ";
}
int main()
{
   freopen("DOANCONLE.inp","r",stdin);
   freopen("DOANCONLE.out","w",stdout);
   doc();
   xuli();
}
