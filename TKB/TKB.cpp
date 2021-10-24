#include <bits/stdc++.h>

using namespace std;
ifstream f1("tkb.inp");
ofstream f2("tkb.out");
int n,m;
int a[10000][10000],b[10000][10000];
int sum=0;
void doc()
{
    f1>>m>>n;
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            f1>>a[i][j];
            sum+=a[i][j];
        }
    }
}
void xuli()
{
    int tam=0;
    int c[10000];
    while (sum>0)
    {
        tam++;
        for (int i=1;i<=m;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (c[j]==0 && a[i][j]>0)
                    {
                        c[j]=1;
                        b[tam][i]=j;
                        a[i][j]--;
                        sum--;
                        break;
                    }
            }
        }
        for(int i=1;i<=n;i++)
            c[i]=0;
    }
    f2<<tam<<endl;
    for (int i=1;i<=tam;i++)
    {
        for (int j=1;j<=m;j++)
        {
            f2<<b[i][j]<<" ";
        }
        f2<<endl;
    }
}
int main()
{
    doc();
    xuli();
}
