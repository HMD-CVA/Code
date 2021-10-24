#include <bits/stdc++.h>

using namespace std;
//ifstream f1("dijkstra.inp");
//ofstream f2("dijkstra.out");
int n,m;
int u,v,k,s,t;
int a[10000][10000];
bool fre[10000];
int d[10000];
void doc()
{
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>k;
        a[u][v]=k;
        a[v][u]=k;
    }
}
void dijkstra(int s, int t)
{
    int u;
  int truoc[10000];
  int minp=INT_MAX;
    for(int i=1;i<=n;i++)
        d[i]=INT_MAX;
    for(int j=1;j<=n;j++)
    {
        d[j]=a[s][j];
        truoc[j]=s;
        fre[j]=false;
    }
    d[s]=0;
    fre[s]=true;
    while(fre[t]==false)
    {
        for (int i=1;i<=n;i++)
            {
                if ((fre[i]==false)&&(minp>d[i]))
                {
                    truoc[i]=u;
                    u=i;
                    minp = d[i];
                }
            }
        fre[u] = true;
        if (fre[t]==false)
        {
            for (int i= 1;i<=n;i++)
            {

                if ((fre[i]==false) && (d[u]+a[u][i]<d[i]))
                {
                   d[i] = d[u] + a[u][i];
                   truoc[i]=u;
                }
            }
        }
    }
    cout<<d[t]<<endl;
    int j=truoc[t];
    while(j!=s)
    {
        cout<<j<<" ";
        j=truoc[j];
    }
    cout<<s;
}
int main()
{
    doc();
    dijkstra(s,t);
}
