#include <bits/stdc++.h>
using namespace std;
int n,x,demx=0;
int a[10000];
void doc()
{
	cout<<"Nhap so phan tu cua day: ";
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<<"x= ";
    cin>>x;
}
void xuli()
{
    for(int i=1;i<=n;i++)
    	for(int j=i+1;j<=n;j++)
    	if(a[i]>a[j])
    		swap(a[i],a[j]);
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
        if(a[i]==x)
            demx++;
    }
    cout<<endl<<"So lan xuat hien cua x la: "<<demx<<endl;
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

