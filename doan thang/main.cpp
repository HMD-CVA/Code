#include <bits/stdc++.h>

using namespace std;
int n;
float a[100001];
int dem=0;
float x;
void nhap()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
}
void xuli()
{
    sort(a+1,a+n+1);
    for(int i=1;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
                x=(a[i]+a[j])/2;
                int l=i,r=j;
                int mid;
                while(l<=r)
                {
                    mid=(l+r)/2;
                    if(x==a[mid])
                    {
                        dem++;
                        break;
                    }
                    else
                    {
                        if(x<a[mid])
                        {
                            r=mid-1;
                        }
                        if(x>a[mid])
                        {
                            l=mid+1;
                        }
                    }
                }
        }
    }
    cout<<dem;
}
int main()
{
    nhap();
    xuli();
    return 0;
}
