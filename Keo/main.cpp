#include <bits/stdc++.h>
using namespace std;
bool kt(long long k, long long n)
{
    long long a=n;
    long long an=0;
    while(a!=0)
    {
        if (a<=k)
        {
           an+=a;
           a=0;
        }
        else
        {
            an+=k;
            a-=k;
        }
        a-=a/10;
    }
    if (an*2>=n) return true;
    else return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    long long dau=1,cuoi=n,luu=0;
    while(dau<=cuoi)
    {
        long long k=(dau+cuoi)/2;
        if (kt(k,n))
        {
            luu=k;
            cuoi=k-1;
        }
        else
        {
            dau=k+1;
        }
    }
    cout << luu;
}
