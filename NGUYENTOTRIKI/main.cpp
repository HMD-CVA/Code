#include <bits/stdc++.h>
using namespace std;
int t,k;
int64_t p1[10001];
int64_t p2[10001];
bool prime(int x)
{
    if(x==2)
        return true;
    else if(x<2)
        return false;
    else
    {
        for(int i=2;i<=sqrt(x);i++)
            if(x%i==0)
                return false;
        return true;
    }
}
void getval()
{
    int i=1;
    p1[i]=3;
    p2[i]=p1[i]+6;
    while(i<=10000)
    {
        if(prime(p1[i]) && prime(p2[i]))
        {
            i++;
            p1[i]=p1[i-1]+2;
            p2[i]=p2[i-1]+2;
        }
        else
        {
            p1[i]+=2;
            p2[i]+=2;
        }
    }
}
int main()
{
    /*freopen("NTTK.inp","r",stdin);
    freopen("NTTK.out","w",stdout);*/
    getval();
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>k;
        cout<<p1[k]<<" "<<p2[k]<<endl;
    }
}
