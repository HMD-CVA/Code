#include <bits/stdc++.h>

using namespace std;

int n,m,u,v,w;
int parent[10000], sizee[10000];

struct kai
{
    int s;
    int f;
    int gt;
};
kai a[10000],b[10000];
void doc()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>u>>v>>w;
        a[i].s = u;
        a[i].f = v;
        a[i].gt = w;
    }
}
void qs(int l,int r)
{
	int i=l,j=r;
	int x=a[(l+r)/2].gt;
	while(i<=j)
	{
		while(a[i].gt<x) i++;
		while(a[j].gt>x) j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(l<j) qs(l,j);
	if(i<r) qs(i,r);
}
int find_set(int u)
{
    if(u == parent[u])
        return u;
    return find_set(parent[u]);
}
int find_setpro(int u)
{
    if(u == parent[u])
        return u;
    return parent[u] = find_setpro(parent[u]);
}
int union_set(int r1, int r2)
{
    if(r1 < r2)
    {
        r2 = r1;
    }
    else
        r1 = r2;
    return r1;
}
void union_setpro(int r1, int r2)
{
    if(sizee[r1] < sizee[r2])
    {
        parent[r1] = parent[r2];
        sizee[r2] += sizee[r1];
        //return parent[r1];
        //return sizee[r2];
    }
    else
    {
        parent[r2] = parent[r1];
        sizee[r1] += sizee[r2];
        //return parent[r2];
        //return sizee[r1];
    }

}
void kruskal()
{
    int d = 0;
    int h=1;
    for(int i=1; i<=n; i++)
        parent[i] = i;
    for(int j=1; j<=m; j++)
    {
        int r1 = find_set(a[j].s);
        int r2 = find_set(a[j].f);
        if(r1 != r2)
        {
            b[h].s = a[j].s;
            b[h].f = a[j].f;
            h++;
            d += a[j].gt;
            int x = union_set(r1,r2);
            parent[a[j].s] = x;
            parent[a[j].f] = x;
        }
        if(h == n)
            break;
    }
    if(h < n-1)
        cout<<"khong co cay khung nho nhat";
    else
    {
        cout<<d<<endl;
        for(int i=1; i<h; i++)
        {
            cout<<b[i].s<<" "<<b[i].f<<endl;
        }
    }

}
void kruskal_pro()
{
    int d = 0;
    int x = 0;
    for(int i=1; i<=n; i++)
        sizee[i] = 1;
    int h=1;
    for(int i=1; i<=n; i++)
        parent[i] = i;
    for(int j=1; j<=m; j++)
    {
        int r1 = find_setpro(a[j].s);
        int r2 = find_setpro(a[j].f);
        if(r1 != r2)
        {
            b[h].s = a[j].s;
            b[h].f = a[j].f;
            h++;
            d += a[j].gt;
            union_setpro(r1,r2);
            parent[a[j].s] = parent[r1];
            parent[a[j].f] = parent[r1];
            x = max(sizee[r1],sizee[r2]);
        }
        if(x == n)
            break;
    }
    if(x < n-1)
        cout<<"khong co cay khung nho nhat";
    else
    {
        cout<<d<<endl;
        for(int i=1; i<h; i++)
        {
            cout<<b[i].s<<" "<<b[i].f<<endl;
        }
    }

}
int main()
{
    freopen("krus.inp","r",stdin);
    freopen("krus.out","w",stdout);
    doc();
    qs(1,m);
    kruskal_pro();
}
