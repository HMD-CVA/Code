#include <bits/stdc++.h>

using namespace std;

ifstream f1("kv.inp");
ofstream f2("kv.out");

long long n,k;
long long a[100001];
long long nam[100001],nu[100001];
void nhap()
{
    f1>>n>>k;
    for(long long i=1;i<=n;i++)
    {
        f1>>a[i];
    }
}
/*void process()
{
    long long t=1,g=1;
    long long e,f,d=0;
    for(long long i=1;i<=n;i++)
    {
        if(a[i]<0)
        {
            nu[g]=abs(a[i]);
            g++;
        }
        else
        {
            nam[t]=a[i];
            t++;
        }
    }
    for(e=1;e<t;e++)
    {
        for(f=1;f<g;f++)
        {
            if(nam[e]-nu[f]<=k && nam[e]>=nu[f])
            {
                d++;
            }
        }
    }
    f2<<d;
}*/
void process()
{
    stack<long long> b,c;
    long long g=1;
    long long d=0;
    for(long long i=1;i<=n;i++)
    {
        if(a[i]<0)
        {
            c.push(abs(a[i]));
        }
        else
        {
            b.push(a[i]);
        }
    }
    while(!b.empty())
    {
        while(!c.empty())
        {
            if(b.top()-c.top()<=k && b.top()>=c.top())
            {
                d++;
            }
            c.pop();
        }
        b.pop();
    }
    f2<<d;
}
int main()
{
    nhap();
    process();
}
