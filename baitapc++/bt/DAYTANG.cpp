#include<bits/stdc++.h>
using namespace std;
int n,a[1000],l[1000],t[1000];
void nhap()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
}
void daycon()
{
    a[0]=MIN;
    a[n+1]=MAX;
    l[n+1]=1;
    int csmax=n+1;
    for (int i=n;i>=0;i--)
    {
        csmax=n+1;
        for (int j=i+1;j<=n+1;j++)
            if (a[j]>a[i] && l[j]>l[csmax]) csmax=j;
        l[i]=l[csmax]+1;
        t[i]=csmax;
    }
    cout<<l[0]-2<<endl<<t[0]<<" ";
    i=t[0];
    while (i!=n+1)
    {
        cout<<"a[",i,"]="a[i];
        i=t[i];
    }
}
int main()
{
	freopen("DAYCON.inp","r",stdin);
	freopen("DAYCON.out","w",stdout);
    nhap();
    daycon();
}
