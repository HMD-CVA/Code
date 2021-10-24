#include <bits/stdc++.h>
using namespace std;
ifstream f1("ployd.inp");
ofstream f2("ployd.out");
int a[1000][1000],d[1000][1000],p[1000][1000];
int n,u,v;
void doc()
{
 f1>>n>>u>>v;
 for (int i = 1; i <= n; i++)
 {
  for (int j = 1; j <= n; j++)
  {
   f1>>a[i][j];
   if (i!=j && a[i][j]==0)
    a[i][j]=INT_MAX;
  }
 }
}
void floyd()
{
 for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            d[i][j]=a[i][j];
            if(d[i][j]==INT_MAX) p[i][j]=0;
            else p[i][j]=j;
        }
    }
 for (int k=1;k<=n;k++)
    {
    for (int i=1;i<=n;i++)
        {
        for (int j=1;j<=n;j++)
            {
                if (d[i][k]!=INT_MAX && d[i][j]>(d[i][k] + d[k][j]))
                {
                d[i][j]=d[i][k]+d[k][j];
                p[i][j]=p[i][k];
               }
            }
        }
    }
  f2<<d[u][v]<<endl;
  f2<<u<<" ";
  while (u!=v)
  {
   cout<<(p[u][v])<<" ";
   u=p[u][v];
  }
}

int main()
{
 doc();
 floyd();
}
