#include <bits/stdc++.h>
using namespace std;
int n,kq=1,p=0,q=0,t;
vector<int>a;
vector<pair<int,int>> b;
void nhap()
{
    freopen("in.inp","r",stdin);
    cin >> n;
    a.resize(2*n);
    b.resize(2*n+1);
    for (int i=0;i<n;i++)
    {
        cin >> t;
        a[i]=t;
        a[n+i]=t;
    }
    b[p]=make_pair(a[2*n-1],2*n-1);
    for (int i=2*n-2;i>=0;i--)
    {
        while(p>=q && b[p].first <= a[i])p--;
        b[++p]=make_pair(a[i],i);
        while(q<q && b[q].second-i>=n) q++;
        kq=max(kq,p-q+1);
    }
    cout << kq;
}
int main()
{
    nhap();
}