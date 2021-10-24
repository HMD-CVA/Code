#include <bits/stdc++.h>
using namespace std;
string s;
int64_t a[1001];
char b[1001];
int l,r,cnt=1;
int char2num(int l, int r)
{
    int num = 0;
    int q=0;
    for(int i=r-1;i>=l;--i)
    {
        num+=(int)(s[i]-'0')*pow(10,q);
        q++;
    }
    return num;
}
int main()
{
    cin>>s;
    s+='+';
    int n=s.length();
    l=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='+' || s[i]=='-')
        {
            r=i;
            b[cnt]=s[i];
            a[cnt]=char2num(l,r);
            l=r+1;
            cnt++;
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        if(b[i]=='+')
            a[i+1]=a[i]+a[i+1];
        else
            a[i+1]=a[i]-a[i+1];
    }
    cout<<a[cnt];
}
