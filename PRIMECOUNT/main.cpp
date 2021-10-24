#include <bits/stdc++.h>

using namespace std;
ifstream f1("primecount.inp");
ofstream f2("primecount.out");
int n;
struct nt
{
    int s;
    int f;
};
nt a[10000];
void doc()
{
    f1>>n;
    for(int i=1;i<=n;i++)
    {
        f1>>a[i].s>>a[i].f;
    }
}
bool snt(int a)
{
    bool kt=true;
    if(a<2) kt=false;
    else
    {
        for(int i=2;i<=sqrt(a);i++)
        {
            if(a%i==0)
            {
                kt=false;
                break;
            }
        }
    }
    return kt;
}
void xl()
{
    int d=0,h=1;
    int b[10000];
    for(int i=1;i<=n;i++)
    {
        for(int j=a[i].s;j<=a[i].f;j++)
        {
            if(snt(j))
                d++;
        }
        b[i]=d;
        d=0;
    }
    for(int i=1;i<=n;i++)
    {
        f2<<b[i]<<endl;
    }
}
int main()
{
   doc();
   xl();
}
