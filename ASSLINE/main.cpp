#include <bits/stdc++.h>

using namespace std;
ifstream f1("ASSLINE.inp");
ofstream f2("ASSLINE.out");
int n,x,y;
int a[1000],b[1000];
void doc()
{
    f1>>n>>x;
    for(int i=1;i<=x;i++)
        f1>>a[i];
    f1>>y;
    for(int j=1;j<=y;j++)
        f1>>b[j];
}
void xl()
{
    int d=0,e=0;
    while(e<=n)
    {
        d++;
        for(int i=1;i<=x;i++)
        {
            if(d>=a[i])
                e++;
        }
    }
    f2<<d<<endl;
    sort(a+1,a+n+1);
    int h=a[1],k=0;
    while(k<=n)
    {
        h++;
        for(int j=1;j<=y;j++)
        {
            if(h-a[1]>=b[j])
                k++;
        }
    }
    f2<<h+1;
}
int main()
{
    doc();
    xl();
}
