#include <bits/stdc++.h>
using namespace std;
vector <int> vt[1005];
int n,m;
int c[1005][1005];
bool del[1005];
void doc()
{
    int u,v,w;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        vt[u].push_back(v);
        vt[v].push_back(u);
        c[u][v]=w;
        c[v][u]=w;
    }
}
void merge1(int s, int t)
{

}
int main()
{
    freopen("MINCUT.INP","r",stdin);
    freopen("MINCUT.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    doc();
    for(int i=1;i<=n;i++)
        del[i]=false;
}
