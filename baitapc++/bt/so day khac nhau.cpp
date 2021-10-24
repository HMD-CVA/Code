#include <bits/stdc++.h>
using namespace std;
typedef string bignum;
string s;
int giaithua(int a)
{
    int GT=1;
    for(int i=1;i<=a;i++)
        GT=GT*i;
    return GT;
}
int sohoanvi(string s)
{
    int dem[26];
    int x,j,i=0;
    for (i=0;i<26;i++)
        dem[i]=0;
    for (int i=0;i<s.length();i++)
        dem[s[i]-97]++;
    int n=1;
    for(j=0;j<26;j++)
    {
        if (dem[j]!=0)
            n=n*(giaithua(dem[j]));
    }
    int k;
     k=giaithua(s.size())/n;
    return k;
}
int main()
{
    string s;
    cout<<"Nhap xau s: ";cin>>s;
    cout<<sohoanvi(s);
    //cout<<giaithua(2);
    return 0;
}




