#include <bits/stdc++.h>
using namespace std;
int n,u,v;
string s[1000];
struct toado
{
    int x;
    int y;
};
toado a[1];
int U1(int u,int v)
{
    a[1].x=u;
    a[1].y=v+1;
    cout << a[1].x <<"  " << a[1].y;
}
int D1(int u, int v)
{
    a[1].x=u;
    a[1].y=v-1;
    cout << a[1].x <<"  " << a[1].y;
}
int L1(int u, int v)
{
    a[1].x=u-1;
    a[1].y=v;
    cout << a[1].x <<"  " << a[1].y;
}
int R1(int u, int v)
{
    a[1].x=u+1;
    a[1].y=v;
    cout << a[1].x <<"  " << a[1].y;
}
void nhap()
{
    freopen("in.inp","r",stdin);
    cin >> n;
    a[1].x=0;
    a[1].y=0;
    for (int i=1;i<=n;i++)
    {
        cin >> s[i];
        if (s[i]=="U") U1(a[1].x,a[1].y);
        if (s[i]=="D") D1(a[1].x,a[1].y);
        if (s[i]=="L") L1(a[1].x,a[1].y);
        if (s[i]=="R") R1(a[1].x,a[1].y);
    }
    for (int i=1;i<=n;i++)
    {
        cout << s[i];
    }
    cin >> u >> v;
    cout << a[1].x <<"  " << a[1].y;
}
int main()
{
    nhap();

}
