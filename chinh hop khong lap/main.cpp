#include <bits/stdc++.h>

using namespace std;

int n,k;
int x[10000],d[10000];
void nhap()
{
    cin>>n>>k;
}
void gn()
{
    for(int i=1;i<=k;i++)
        cout<<x[i]<<" ";
    cout<<endl;
}
void process(int i)
{
    int j;
    for(int j=1;j<=n;j++)
    {
        if(d[j]==0)
        {
            x[i]=j;
            if(i==k)
                gn();
            else
            {
                d[j]=1;
                process(i+1);
                d[j]=0;
            }
        }
    }
}
int main()
{
    nhap();
    process(1);
}
