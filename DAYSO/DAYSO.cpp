#include <bits/stdc++.h>

using namespace std;
ifstream f1("dayso.inp");
ofstream f2("dayso.out");
int n;
int a[100000];
void doc()
{
    f1>>n;
    for(int i=1;i<=n;i++)
        f1>>a[i];
}
void xl()
{
    sort(a+1,a+n+1);
    int h=1,s=0,b[100000];
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0)
        {
            b[h]=a[i];
            h++;
        }
    }
    f2<<b[1]<<" "<<b[h-1]<<endl;
    for(int i=1;i<=h-1;i++)
    {
        s+=b[i];
    }
    f2<<s;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    doc();
    xl();
}
