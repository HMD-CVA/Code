#include<bits/stdc++.h>
using namespace std;
int main()
{
   // freopen ("NGONDOI.INP","r",stdin);
   // freopen ("NGONDOI.OUT","w",stdout);
    int a[100001],n;
    bool k=false;
    int kq=0;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=2;i<=n;i++)
    {
        if (k==false)
        {
            if (a[i]>a[i-1])
            {
                kq++;cout<<i<<" ";
            }
        }
        if (a[i]>a[i-1]) k=true;
        else k=false;
    }
    cout << kq;
}
