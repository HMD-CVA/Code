#include <bits/stdc++.h>
#define MOD 111539786
using namespace std;

struct matrix
{
    int val [3][3];
};
matrix a,c,c1;
int t;
long long n,T;

matrix mul(matrix a,matrix b)
{
    matrix c;
    for (int i=1;i<=2;i++)
        for (int j=1;j<=2;j++)
    {
        c.val[i][j]=0;
        for (int k=1;k<=2;k++)
            c.val[i][j]+=a.val[i][k]*b.val[k][j];
    }
    return c;
}
matrix mul_k(matrix a,long long k)
{
    matrix x;
    if (k==1) return a;
    x=mul_k(a,k/2);
    x=mul(x,x);
    if (k%2) x=mul(x,a);
    return x;
}
void xuat()
{
 c=mul_k(a,n-1);
 c1=mul_k(a,n);
 cout << (c.val[1][1]+c.val[1][2])%MOD<<" "<< (c1.val[1][1]+c1.val[1][2])%MOD+(c.val[1][1]+c.val[1][2])%MOD -2<<endl;
}
void ktao()
{
    a.val[1][1]=1;
    a.val[1][2]=1;
    a.val[2][1]=1;
    a.val[2][2]=0;
}
int main()
{
    ktao();
        cin>>n;
        if (n==1) cout<<1<<" "<<1<<endl;
        else if (n==2) cout<<2<<" "<<3<<endl;
        else if (n==3) cout<<3<<" "<<6<<endl;
        else
        xuat();
}
