#include <bits/stdc++.h>
using namespace std;
ifstream f1("bai1.inp");
ofstream f2("cau1.out");
ofstream f3("cau2.out");
ofstream f4("cau3.out");
int n,a[10000][10000],before[100000],d=0;
bool visited[100000];
queue <int> q;
void doc()
{
    f1>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            f1>>a[i][j];
}
void DFS(int u)
{
    if (d==0) f2<<u<<endl;
    if (d>0) f4<<u<<endl;
    visited[u] = true;
    for (int v=1;v<=n;v++)
        {
            if (a[u][v]==1 && visited[v] == false )
                DFS(v);
        }

}
void BFS(int s)
{
     q.push(s);
     visited[s]=true;
     while (!q.empty())
     {
        int u = q.front();
        q.pop();
        f2<<u<<endl;
        for (int v=1; v<=n; v++)
            if (visited[v]==false && a[u][v]==1)
            {
                visited[v] = true;
                q.push(v);
            }
     }
}
void DFS1(int u)
{
    visited[u] = true;
    for (int v=1;v<=n;v++)
        if ( a[u][v]==1 && visited[v] == false )
        {
            before[v]=u;
            DFS1(v);
        }
}
void xl()
{
    memset (visited,false,n+1);
    before[1]=0;
    int res[1000] ,r=5 ;
    DFS1(1) ;
    if ( visited[5] == false ) f3 << "khong co duong di" ;
    else
    {
        int i = 5 ; res[5] = 5 ;
        while ( i > 1 )
        {
           r -- ;
           res[r]=before[i];
           i = before[i] ;
        }
        for (int i=1;i<=5;i++) f3<<res[i]<<" " ;
    }
}
void xuli()
{
    d=1;
    f4 << "thanh phan lien thong thu " << d << " la :" << endl;
    DFS(1);
    for (int i=1;i<=n;i++)
        if (visited[i]==false)
    {
        d++;
        f4 << "thanh phan lien thong thu " << d << " la :" << endl;
        DFS(i);
    }
    f4 << "so thanh phan lien thong la: " << d;
}
int main()
{
    doc();
    memset (visited , false, n+1);
    DFS(1);
    BFS(1);
    xuli();
    xl();
}
