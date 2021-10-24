#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[10000],sa[1000000],maxx=0,k,dem=0;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        if (a[i]>0) dem++;
        sa[a[i]]++;
    }
    cout << dem << endl;
    for (int i=1;i<=n;i++)
    {
        if (sa[i]>1)
        {
            maxx=max(maxx,sa[i]);
            k=i;
        }
    }
    cout << k << " " << maxx;
}
