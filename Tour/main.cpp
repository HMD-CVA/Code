#include <bits/stdc++.h>
using namespace std;
int n,h,lmin=1e9,lh=1e9,kq1=0,kq2=0,prh=1e9,llen=0;
void nhap()
{
    freopen("in.inp","r",stdin);
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> h;
        if (h==lh) llen++;
        else
        {
            if (prh<lh && lh>h && llen<lmin)
            {
                lmin=llen;
                kq1=i-llen-1;
                kq2=i;
                if (lmin==1) break;
            }
            prh=lh;
            lh=h;
            llen=1;
        }
    }
    if (kq1==0) cout << "0";
    else cout << kq1 << endl << kq2;
}
int main()
{
    nhap();
}
