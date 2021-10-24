#include <bits/stdc++.h>

using namespace std;
ifstream f1("hamilton.inp");
ofstream f2("hamilton.out");
int n,m,u,v,visited[10000];
int a[1000][1000];
void doc()
{
    f1>>n>>m;
    for(int i=1;i<=m;i++)
    {
    	f1>>u>>v;
    	a[u][v]=1;
    	a[v][u]=1;
	}
}
void hamilton(int i)
{
    int b[10000];
    for(int j=1;j<=n;j++)
    {
        if(a[b[i-1]][j]==1 && visited[j]==0)
        {
            b[i]=j;
            visited[j]=1;
            if(i<=n) hamilton(i+1);
            else
            {
                if(b[i]==b[1])
                {
                    for(int k=n;k>=1;k--)
                    {
                        f2<<b[k]<<" ";
                    }
                    f2<<endl;

                }
            }
            visited[j]=0;
        }
    }
}
int main()
{
    doc();
    hamilton(2);
}
