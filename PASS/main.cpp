#include <bits/stdc++.h>
using namespace std;
int n,res=0;
string pass[20005];
int check(string a, string b)
{
    int x=a.size();
    int y=b.size();
    int u=a.size();
    int v=b.size();
    for(int i=0;i<min(x,y);i++)
    {
        for(int j=0;j<max(x,y);j++)
            if(a[i]==b[j])
            {
                u--;
                v--;
            }
    }
    if(u==0 || v==0)
    {
        if(u==0 && v==0)
            return 2;
        return 1;
    }
    return 0;
}
int main()
{
    freopen("PASS.INP","r",stdin);
    freopen("PASS.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>pass[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            res+=check(pass[i],pass[j]);
        }
    }
    cout<<res;
}
