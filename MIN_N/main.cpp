#include <bits/stdc++.h>
using namespace std;
priority_queue <int,vector<int>,greater<int>> pq;
void doc()
{
    int n,a;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        pq.push(a);
    }
}
int main()
{
    freopen("MIN_N.inp","r",stdin);
    freopen("MIN_N.out","w",stdout);
    doc();
    int n=0,a;
    while(!pq.empty())
    {
        a=pq.top();
        if(a<=n)
        {
            n=a;
            pq.pop();
        }
        else
        {
            cout<<n;
            break;
        }
        n++;
    }
}
