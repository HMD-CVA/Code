#include <bits/stdc++.h>

using namespace std;
ifstream f1("khoa.inp");
ofstream f2("khoa.out");
int n;
int kt[10000];
struct key
{
    int t;
    int s;
};
key a[10000];
void doc()
{
    f1>>n;
    for(int i=1;i<=n;i++)
    {
        f1>>a[i].s;
        a[i].t=i;
    }
}
void xl()
{
    int h=1,b[10000];
    int d=1;
    for(int i=1;i<=n;i++)
    {
            kt[i]=1;
        for(int j=1;j<=n;j++)
        {
            if(a[i].s==a[j].t && kt[a[j].t]==0)
            {
                kt[a[j].t]=1;
                i=a[j].s;
            }
            else
            {
                d++;
                kt[j]=1;
                j++;
            }
        }
        f2<<endl;
        b[h]=d;
        h++;
        d=0;
    }
    sort(b+1,b+h);
    f2<<b[1];
}
int main()
{
    doc();
    xl();
}
