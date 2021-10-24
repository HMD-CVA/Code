#include <bits/stdc++.h>
using namespace std;
long long n,a[20001],sa[20001],maxx=0,kq=0,dem=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n ;
    for (long long i=1;i<=n;i++) 
    {
        cin >>  a[i];
        sa[a[i]]++;
        maxx=max(maxx,a[i]);
    }
    for (int i=1;i<=maxx;i++) cout << sa[i]  <<" ";
    long long max1=maxx;
    for (long long i=maxx;i>=1;i--)
    {
        if (sa[i] > kq && max1<i)
        {
            kq=sa[i];
            dem=i;
            max1=i;
        }
    }
    cout << dem << " " << kq;
}
