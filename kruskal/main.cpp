#include <bits/stdc++.h>

using namespace std;
int n;
int a[1000][1000],kt[1000][1000];
void doc()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
}
struct dothi
{
    int s;
    int f;
    int x;
};
dothi b[100000];
void xl()
{
    int h=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j && a[i][j]!=0)
            {
                b[h].x=a[i][j];
                b[h].s=i;
                b[h].f=j;
                h++;
            }
        }
    }
    for(int i=1;i<=h-1;i++)
    {
        for(int j=i+1;j<=h-1;j++)
        {
            if(b[i].x>b[j].x)
                swap(b[i],b[j]);
        }
    }
    int d=0,k=1;
    while(d<n-1)
    {
        if(kt[b[k].s][b[k].f]==0 && b[k].s!=b[k].f)
        {
            cout<<b[k].s<<" "<<b[k].f<<endl;
            kt[b[k].s][b[k].f]=1;
            kt[b[k].f][b[k].s]=1;
            d++;
        }
        k++;
    }

}
int main()
{
    doc();
    xl();
}
