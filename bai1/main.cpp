#include <bits/stdc++.h>
using namespace std;
int n,demx=0,x;
int a[10000];
void doc()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>x;
}
void xuli()
{
    sort(a,a+n);
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
        if(a[i]==x)
            demx++;
    }
    cout<<endl<<demx<<endl;
    cout<<"So phan tu nho hon hoac bang x: ";
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=x)
            cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"So phan tu lon hon x: ";
    for(int i=1;i<=n;i++)
    {
        if(a[i]>x)
            cout<<a[i]<<" ";
    }
}
int main()
{
    doc();
    xuli();
}

