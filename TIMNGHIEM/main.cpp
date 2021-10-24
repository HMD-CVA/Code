#include <bits/stdc++.h>
using namespace std;
int a[5001];
int n,r,d=0;
bool prime(int n)
{
    if(n<2)
        return false;
    if(n==2)
        return true;
    else
    {
        for(int i=2;i<=sqrt(n);i++)
            if(n%i==0)
            {
                return false;
                break;
            }
        return true;
    }
}
int main()
{
    cin>>n;
    r=0;
    for(int i=2;i<=n;i++)
    {
        if(prime(i))
        {
            r++;
            a[r]=i;
        }
    }
    for(int i=1;i<=r;i++)
    {
        for(int j=i;j<=r;j++)
        {
            for(int k=j;k<=r;k++)
                if(a[i]+a[j]+a[k]==n)
                {
                    cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
                    d++;
                }
        }
    }
    if(d==0)
        cout<<-1;
}
