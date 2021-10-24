#include <bits/stdc++.h>
using namespace std;
int64_t n,t,x,a[1000001];
void xuli()
{
    cin>>n;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>x;
        if(sqrt(x)==(int)sqrt(x))
            cout<<x+1<<endl;
        else
        {
            if(sqrt(x-1)==(int)sqrt(x-1))
                cout<<x<<endl;
            else
            {
                int64_t k=(int)sqrt(x)+1;
                int64_t k2=k*k+1;
                cout<<k2<<endl;
            }
        }
    }
}
int main()
{
    freopen("TKNP3.inp","r",stdin);
    freopen("TKNP3.out","w",stdout);
    xuli();
}
