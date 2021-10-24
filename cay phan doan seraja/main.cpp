#include <bits/stdc++.h>

using namespace std;
//ifstream f1("inp");
//ofstream f2("out");

int n,u,v,m,a,b;
string s;
struct node
{
    int kq;
    int open;
    int close;
};
node buil(int x,int y, int z)
{
    node p;
    p.kq = x;
    p.open = y;
    p.close = z;
    return p;
}
node st[5000000];
node add(node left, node right)
{
    node p;
    int tmp = min(left.open, right.close);
    p.kq = left.kq + right.kq + tmp*2;
    p.open = left.open + right.open - tmp;
    p.close = left.close + right.close - tmp;
    return p;
}
void started(int root, int l, int r)
{
    if(l == r)
    {
        if(s[l] == '(')
            st[root] = buil(0,1,0);
        else
            st[root] = buil(0,0,1);
        return;
    }
    int mid = (l+r)/2;
    started(root*2, l, mid);
    started(root*2+1, mid+1, r);
    st[root] = add(st[root*2],st[root*2+1]);
}
node process(int root, int l, int r, int u, int v)
{
    if(l > v || r < u)
        return buil(0,0,0);
    if(u <= l && v >= r)
    {
        return st[root];
    }
    int mid = (l+r)/2;
    return add(process(root*2,l,mid,u,v),process(root*2+1,mid+1,r,u,v));
}
int main()
{
    node p;
    cin>>s>>m;
    n = s.length();
    s=" "+s;
    started(1,1,n);
    for(int i=1; i<=m; i++)
    {
        cin>>a>>b;
        p = process(1,1,n,a,b);
        cout<<p.kq<<endl;
    }
}
