#include <bits/stdc++.h>
using namespace std;
int n,l;
struct da
{
    int x;
    int w;
    int d;
};
da a[1000],t[1000];
void nhap()
{
    freopen("in.inp","r",stdin);
    cin >> n >> l;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i].w >> a[i].x >> a[i].d;
        if (a[i].d==1) t[i].x=l-a[i].x;
        if (a[i].d==-1) t[i].x=a[i].x;
    }
}
void getww(int d, int l ,int r)
{
    if (d==1) {w=a[r].w;r--;}
    if (d==-1){w=a[l].w;l++;}
}
int main()
{
    int l=1;int r=n;
    //sorrt t theo x;
    for (int i=1;i<=n;i++)
    {
        w=getww(t[i].d,l,r)
        timee=t[i].x;
    }
}
