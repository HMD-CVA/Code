#include<bits/stdc++.h>
using namespace std;
int n,a[1000],k,x[100],s, kt[1000];
void Xuatnghiem()
{
    s=0;
    for (int i=1;i<=k;i++)
    {
        if(x[i]==1)
        {
            s+=a[i];
            kt[s]=1;
        }
    }
    cout << endl;
    for (int i=1;i<=n;i++) cout << kt[i] << " ";
    cout << endl;
}
void ToHop (int i)
{
    for (int j=0;j<=1;j++)
    {
        x[i]=j;
        if (i==k) Xuatnghiem();
        else ToHop(i+1);
    }
}
int main()
{
    freopen("in.inp","r",stdin);
    cin >> n;
    memset(kt,0,n);
    for (int i=1;i<=n;i++) cin >> a[i];
    k=n;
    x[0]=0;
    ToHop(1);
    for (int i=1;i<=10000;i++)
    {
        if (kt[i]==0)
        {
            cout << i << " ";
            break;
        }
    }
}

