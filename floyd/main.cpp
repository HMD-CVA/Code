#include <bits/stdc++.h>
using namespace std;
ifstream f1("floyd.inp");
ofstream f2("floyd.out");
int a[1000][1000],d[1000][1000],p[1000][1000];
int n,m,u,v,s,t,w;
void doc()
{
    f1>>n>>m>>s>>t;
     for(int i=1; i<=n; i++)
     {
         for(int j=1; j<=n; j++)
         {
            if(i == j) a[i][j] = 0;
            else a[i][j] = INT_MAX;
         }
     }
     for (int i=1; i<=m; i++)
    {
         f1>>u>>v>>w;
         a[u][v] = w;
     }
     for(int i=1; i<=n; i++)
     {
         for(int j=1; j<=n; j++)
         {
            f2<<a[i][j]<<" ";
         }
         f2<<endl;
     }
}
void floyd()
{
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n ;j++)
        {
            d[i][j] = a[i][j];
            //f2<<d[i][j]<<" ";
            if(d[i][j] != INT_MAX)
            {
                p[i][j] = j;
            }

        }
        //f2<<endl;
    }
    for (int k=1; k<=n; k++)
    {
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
            {
                if (i != j && d[i][j]>d[i][k]+d[k][j])
                {
                   d[i][j]=d[i][k]+d[k][j];
                   p[i][j]=p[i][k];
                }
            }
        }
    }
    //f2<<s<<" "<<t;
    //f2<<d[s][t]<<endl;
    //f2<<s<<"->";
    /*while (s!=t)
    {
       f2<<p[s][t]<<"->";
       s=p[s][t];
     }*/
}

int main()
{
    doc();
    floyd();
}
