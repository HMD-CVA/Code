#include <bits/stdc++.h>
using namespace std;
int n,m,p,t,b;
int cost=0;
int add[1000];
int bst[1000];
int doc()
{
    cin>>n>>m>>p>>t>>b;
    for(int i=1;i<=m;i++)
        cin>>add[i];
    p+=2;
    bst[1]=1;
    bst[p]=n;
    for(int i=2;i<p;i++)
        cin>>bst[i];
}
void xuli(int k, int f, int r)
{
    for(int i=r;i<=add[k];i++)
    {
        if(bst[f]==i)
        {
            if(bst[f-1]==r)
                cost=cost+b+t*(add[k]-i);
            else
                cost=cost+t*(add[k]-i);
        }
    }
    r=add[k];
    xuli(k+1,f+1,r);
}
int main()
{
    freopen("LUNARNY1.inp.c","r",stdin);
    freopen("LUNARNY1.out.c","w",stdout);
    doc();
    xuli(1,2,1);
    cout<<cost;
}

