#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n,x;
int a[10000],stt[10000],v[10000],b[10000];
int j=1;
void nhap()
{
    cin>>n>>x;
    for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            stt[a[i]]++;
            if(v[a[i]]==0)
            {
                b[j]=a[i];
                j++;
                v[a[i]]=1;
            }
        }
}
int as(int n)
{
    int c[10000];
    c[1]=0;
    c[2]=1;
    c[3]=3;
    int cc=3,i=4;
    while(i<=n/2)
    {
        c[i]=c[i-1]+cc;
        cc++;
        i++;
    }
    return c[n/2];
}
void process()
{
    nhap();
    int t[10000];
    int s=0;
    sort(b+1,b+j);
    j--;
    for(int i=1;i<=j;i++)
    {
        if(t[b[i]]==0)
        {
            if(x%2==0 && b[i]==x/2)
            {
                s+=as(x);
            }
            else
            {
                if(b[j]+b[i]==x)
                {
                    s+=stt[b[i]]*stt[b[j]];
                    i++;
                    j--;
                }
                else if(b[j]+b[i]<x)
                {
                    i++;
                }
                else
                {
                    j--;
                }
            }
            t[b[i]]=1;
            t[b[j]]=1;
        }

    }
    cout<<s;
}
int main()
{
    //nhap();
    process();
}
