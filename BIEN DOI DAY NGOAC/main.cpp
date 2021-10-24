#include <bits/stdc++.h>
using namespace std;
int n,p,f[10000];string s;
void enter()
{
    cin>>n>>p;f[0]=0;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='(') f[i]=f[i-1]+1;
        else f[i]=f[i-1]-1;
    }
}
void process1(int t)
{
    f[t]-=2;
    for(int i=1;i<=n;i++)
    {
        if(f[i]==f[i-1]-1)
        {
            cout<<i<<" ";
            for(int j=i;j<=t;j++)
                f[j]+=2;
                return;
        }
    }
}
void process2(int t)
{
   int mx=2;
   f[t]+=2;
   for(int i=1;i<=t;i++)
   {
       if(f[i]==2)
       {
           cout<<i<<" ";
           for(int j=i;j<=t;j++)
            f[j]-=2;
           return;
       }
   }
}
void process()
{
    int t;cin>>t;int h;
    if(f[t]==f[t-1]+1) h=1;
    else h=-1;
    if(h==1)
    {
        process1(t);
    }
    else
    {
        process2(t);
    }
}
int main()
{
    enter();
    for(int i=1;i<=p;i++) process();
}
