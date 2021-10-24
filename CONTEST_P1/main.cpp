#include <iostream>
using namespace std;
int n;
int a[105][105];
int d[105]={0};
int maxx;
void doc()
{
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        a[u][v]=1;
        a[u][v]=1;
        d[u]++;
        d[v]++;
    }
}
void process()
{
    maxx=d[1];
    for(int i=2;i<=n;i++)
        maxx=max(maxx,d[i]);
    cout<<maxx;
}
int main()
{
    freopen("cc.inp","r",stdin);
    freopen("cc.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    doc();
    process();
}
