#include <bits/stdc++.h>
#define ll long long
#define MAX 30000

using namespace std;

ll n, k;
ll a[MAX], b[MAX], c[MAX];
ll dp[1000][1000];
ll sum = 0, kq = 0;
ll kt[MAX], ktt[MAX];
ll h = 1;
priority_queue<ll, vector<ll>, greater<ll> > q;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i ++)
    {
        cin >> a[i];
        b[i] = a[i];
        q.push(a[i]);
    }
    b[1] = q.top();
    while(q.size() > 1)
    {
        int x = q.top();
        q.pop();
        if(q.top() != x)
        {
            h++;
            b[h] = q.top();
        }
    }
    dp[1][1] = abs(a[1] - b[1]);
    for(ll j = 2; j <= h; j ++)
        dp[1][j] = min(abs(a[1]-b[j]), dp[1][j-1]);
    for(ll i = 2; i <= n; i ++)
        dp[i][1] = abs(a[i]-b[1])+dp[i-1][1];
    for(ll i = 2; i <= n; i ++)
        for(ll j = 2; j <= h; j ++)
            dp[i][j] = min(dp[i][j-1],dp[i-1][j]+abs(a[i]-b[j]));
    cout<<dp[n][h];
}
