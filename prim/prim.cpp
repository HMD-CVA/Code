#include <bits/stdc++.h>

using namespace std;

int n,m,u,v,w;
bool visit[10000];
int d[10000], trace[10000], next[10000];
int a[1000][1000];
typedef pair<int,int> ii;
void doc()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>u>>v>>w;
        a[u][v] = w;
        a[v][u] = w;
    }
    //cout<<a[1][4]<<" ";
}
void process(int s)
{
    int st[10000];
    //int e = s;
    bool kt = true;
    int sum = 0;
    for(int i=1; i<=n; i++)
        d[i] = INT_MAX;
    memset(visit,false,n);
    //memset(trace,s,n);
    //memset(next,0,n);
    visit[s] = true;
    int res = 1;
    int r=1;
    st[res] = s;
    //cout<<d[4];
    while(r <= n-1)
    {
        //priority_queue<ii, vector<ii> ,greater<ii> > p;
        int i=1;
        res++;
        while(i <= n)
        {
            if(a[s][i] != 0 && visit[i] == false)
            {
                //trace[i] = s;
                //next[s] = i;
                d[i] = min(d[i],a[s][i]);
                //p.push(ii(d[i],i));
            }
             i++;
        }
        /*st[res] = p.top().second;
        int minp = p.top().first;
        s = p.top().second;
        while(!p.empty())
            p.pop();
        cout<<s<<" "<<minp<<endl;*/
        int minp = INT_MAX;
        for(int j=1; j<=n; j++)
        {
            if(visit[j] == false && d[j] < minp )
            {
                //cout<<j<<" ";
                minp = d[j];
                //trace[j] = s;
                st[res] = j;
                s = j;
            }
        }
        if(minp != INT_MAX)
        {
            sum += minp;
        }

        visit[s] = true;
        if(d[s] == INT_MAX)
        {
            kt = false;
            break;
        }
        r++;
    }
    //for(int i=1;i<=n;i++)
        //cout<<trace[i]<<" ";
    cout<<sum<<endl;
    if(kt == true)
    {
        int c=1;
        while(c <= n)
        {
         cout<<st[c]<<" ";
         c++;
        }
    }
    else
        cout<<"ko co cay khung nho nhat";
}
int main()
{
    //freopen("prim.inp","r",stdin);
    //freopen("prim.out","w",stdout);
    doc();
    process(1);
}

