#include <bits/stdc++.h>
using namespace std;
int main()
{
    int64_t l,r,k,d13=0,c13=0;
    int64_t s,s1=0,s2=0;
    cin>>l>>r;
    k=r-l+1;
    s1=(r+l)*k/2;
    for(int64_t i=l;i<=r;i++)
    {
        if(i%13==0)
        {
            d13=i;
            break;
        }
    }
    for(int64_t j=r;j>=l;j--)
    {
        if(j%13==0)
        {
            c13=j;
            break;
        }
    }
    k=(c13-d13)/13+1;
    s2=(c13+d13)*k/2;
    s=s1-s2;
    cout<<s;
}
