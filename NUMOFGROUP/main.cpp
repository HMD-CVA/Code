#include <bits/stdc++.h>
using namespace std;
int n,dem=0,s=0;
int a[1000];
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
        if(s!=n)
        {
            s=s+a[i];
            dem++;
            if(s>n)
            {
                s=s-a[i];
                dem--;
            }
        }
    }
    cout<<dem;
}
int main()
{
    freopen("NUMOFGROUP.inp","r",stdin);
    freopen("NUMOFGROUP.out","w",stdout);
    doc();
    xuli();
}
