#include <bits/stdc++.h>
using namespace std;
void remove0(vector<int> &v)
{
    while(v[v.size()-1]==0 && v.size()>1) v.pop_back();
}
void nhap(char s[],vector<int> &a)
{
    for (int i=strlen(s)-1;i>=0;i--)
    {
        a.push_back(a[i]-'0');
    }
    remove0(a);
}
int ss(vector<int> a, vector<int> b)
{
    if (a.size()<b.size()) return 1;
    if (a.size()>b.size()) return -1;
    for (int i=a.size()-1;i>=0;i--)
    {
        if (a[i]>b[i]) return -1;
        if (a[i]<b[i]) return 1;
    }
    return 0;
}
void sum(vector<int> a, vector<int> b, vector<int> &c)
{
    c.clear();
    int l=a.size();
    b.resize(l);
    int du=0,tam;
    for (int i=1;i<=l;i++)
    {
        if (a[i]<b[i]+du)
        {
            c.push_back(a[i]-b[i]-du+10);
            du=1;
        }
        else
        {
            c.push_back(a[i]-b[i]-du);
            du=0;
        }
    }
    remove0(c);
}
void chia(vector<int> a, vector<int> b, vector<int> &c)
{
    c.clear();
    vector<int>cary;
    while(a.size()>0)
    {
        int fin=a.size()-1;
        int star=fin-b.size()+1;
        if (star<0) star=0;
        int c1=star;
        if(cary.size()==0)
        {
            while(c1<=fin)
            {
                cary.push_back(a[star]);
                a.pop_back();
                c1++;
            }
        }
        else
        {
            while(c1<=fin)
            {
                cary.insert(cary.begin(),a[star]);
                a.pop_back();
                c1++;
            }
        }
        if (ss(cary,b)!=-1&&a.size()>0)
        {
            cary.insert(cary.begin(),a[star-1]);
            a.pop_back();
        }
        remove0(cary);
        c1=0;
        while(ss(cary,b)!=1)
        {
            c1++;
            sum(cary,b,cary);
        }
        if (c1>=10)
        {
            int x=c1%10;
            c1/=10;
            int y=c1%10;
            c1/=10;
            c.insert(c.begin(),y);
            c.insert(c.begin(),x);
        }
        else c.insert(c.begin(),c1);
    }
}
void in(vector<int> a)
{
    for (int i=a.size()-1;i>=0;i--)
    {
        cout << a[i];
    }
}
int main()
{
    char a[]="16";
    char b[]="4";
    vector<int> v1,v2,v3;
    nhap(a,v1);
    nhap(b,v2);
    in(v1);
    cout << endl;
    in(v2);
    cout << endl;
}
