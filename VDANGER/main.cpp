#include <bits/stdc++.h>
using namespace std;

const int maxn=100;
const int maxd=10e6;
int n,m,k;
int u,v,c;
int a[1000][1000];

void Init()
{
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            a[i][j]=INT_MAX;

    for (int i=1;i<=m;i++)
    {
        cin>>u>>v>>c;
        a[u][v]=c;
        a[v][u]=c;
    }
}

void Solve()
{
    while(k--)
    {
        int t,u, v;
        cin>>t>>u>>v;
        vector<int> L(n+2,0);
        vector<int> Prev(n+2,0);
        vector<int> Visit(n+2,0);
        for (int i=1;i<=n;i++)    L[i]=maxd;
        L[u]=0;
        while(1)
        {
            int u=0;
            int min1=maxd;
            for (int i=1;i<=n;i++)
            {
                if(!Visit[i] && L[i]<min1)
                {
                    min1=L[i];
                    u=i;
                }
            }
            if(u==0 || u==v) break;
            Visit[u]=1;
            for (int i=1;i<=n;i++)
            {
                if(!Visit[i] && L[i]>L[u]+a[u][i])
                {
                    L[i]=L[u]+a[u][i];
                    Prev[i]=u;
                }
            }
        }
        if(t==0)
        {
            cout<<L[v];
        }
        else
        {
            stack<int> st;
            while(v != u)
            {
                st.push(v);
                v=Prev[v];
            }
            cout<<st.size()+1;
            while(!st.empty())
            {
                cout<<st.top();
                st.pop();
            }
            printf("n");
        }
    }

}

int main()
{
    Init();
    Solve();
}
