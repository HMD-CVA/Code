#include <bits/stdc++.h>

using namespace std;
int j,i,x,a[100005],f[1005][1005],k;
int main()
{
    cin>>x;
    a[1]=1;
    i=1;
    while(a[i]<=x)
    {
        i++;
        a[i]=a[i-2]+a[i-1];
    }
    for(j=0;j<i;j++) f[j][0]=0;
    for(j=0;j<=x;j++) f[0][j]=0;
    for(j=1;j<i;j++)
        for(k=1;k<=x;k++)
    {
        if(a[j]>k)
            f[j][k]=f[j-1][k];
        else
            f[j][k]=max(f[j-1][k],f[j-1][k-a[j]]+a[j]);
    }
    cout<<f[i-1][x]<<endl;
    j=i-1; k=x;
    while(f[j][k]>0)
    {
        if(f[j][k]==f[j-1][k-a[j]]+a[j])
        {
            cout<<a[j]<<" ";

            k=k-a[j];
        }
            j--;
    }
}
