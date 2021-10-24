#include <bits/stdc++.h>

using namespace std;

int n,m,u,v,c;
int a[10000][10000],d[10000][10000];
queue<int>Find;
void doc()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>c;
        a[u][v]=c;
        a[v][u]=c;
        d[u][v]=1;
        d[v][u]=1;
    }
}
bool kt()
{
    int tmp;
    for(int i=1;i<=n;i++)
    {
        tmp=0;
        for(int j=1;j<=n;j++)
            tmp+=d[i][j];
        if(tmp%2!=0)
            return false;
            break;
    }
    return true;
}
void xl(int x)
{
    if(x<=n)
    {
        int s=0;
    Find.push(x);
    while(!Find.empty())
    {
        if(s>=0)
        {
        int i=Find.front();
        for(int j=1;j<=n;j++)
        {
            if(d[i][j]==1)
            {
                Find.push(j);
                s+=a[i][j];
                d[i][j]=0;
                d[j][i]=0;
                break;
            }
        }

            cout<<Find.front()<<" ";
            Find.pop();
        }
        else xl(x+1);
    }
    }
    else
        cout<<"-1";

}
int main()
{
    doc();
    if(kt())
        xl(1);
    else
        cout<<"-1";
}

