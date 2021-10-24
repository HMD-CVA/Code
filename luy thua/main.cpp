#include <bits/stdc++.h>
using namespace std;
long long a,m,b,n,k,t,m1,n1;
long long pow1(long long a, long long n)
{
    if(n == 1) return a%k;
    long long tmp = pow1(a, n/2)%k;
    if(n%2 == 0)
    {
        return tmp*tmp;
    }
    else
        return tmp*tmp*(a%k);
}
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> a >> m >> b >> n >> k;
        cout << (pow1(pow1(a,m)%k,pow1(b,n)%k))%k << endl;
    }
}
