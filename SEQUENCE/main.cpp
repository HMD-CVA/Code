#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[10005],b[10005];
long long dp[10005][10005];
priority_queue <long long> pq;
void doc()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
}

void process()
{
    for(int i=1;i<=n;i++)
        b[i]=a[i];
    sort(b+1,b+n+1);
    pq.push(b[1]);
    for(int i=2;i<=n;i++)
    {
        int x=pq.top();
        if(b[i]!=x)
            pq.push(b[i]);
    }
    m=pq.size();
    int k=1;
    while(!pq.empty())
    {
        int x=pq.top();
        b[k]=x;
        k++;
        pq.pop();
    }
    sort(b+1,b+m+1);
    dp[1][1]=abs(a[1]-b[1]);
    for(int j=2;j<=m;j++)
        dp[1][j]=min(abs(a[1]-b[j]),dp[1][j-1]);
    for(int i=2;i<=n;i++)
        dp[i][1]=abs(a[i]-b[1])+dp[i-1][1];
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=m;j++)
            dp[i][j]=min(dp[i][j-1],dp[i-1][j]+abs(a[i]-b[j]));
    }
    cout<<dp[n][m];
}
int main()
{
    //freopen("SEQUENCE.INP","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    doc();
    process();
}


