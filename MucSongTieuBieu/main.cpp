#include <bits/stdc++.h>
using namespace std;
int r,c,h,w,a[3001][3001],maxx=0,s[500000];
void nhap()
{
    //freopen("in.inp","r",stdin);
    cin >> r >> c >> h >> w;
    for (int i=1;i<=r;i++)
        {
            for (int j=1;j<=c;j++)
            {
                cin >> a[i][j];
            }
        }
}
void Xl()
{
    if (h==1 && w==1)
    {
        cout << r*c;
        exit(0);
    }
    if (h==r && w==c)
    {
        cout << (r*c+1)/2;
        exit(0);
    }
    for (int i=1;i<=r-h+1;i++)
        for (int j=1;j<=c-w+1;j++)
        {
            int dem=0;
            for (int k=i;k<=i+h-1;k++)
                for (int t=j;t<=j+w-1;t++)
                {
                    dem++;
                    s[dem]=a[k][t];
                }
            sort(s+1,s+dem+1);
            maxx=max(maxx,s[(1+dem)/2]);
        }
    cout << maxx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    nhap();
    Xl();
}
