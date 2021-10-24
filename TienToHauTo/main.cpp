#include <bits/stdc++.h>
using namespace std;
long long hasha[1000100],hashb[1000100];
string a,b;
long long power(long long a, long long n)
{
	long long result = 1;
	while (n>0)
    {
		if (n%2==1) result*=a;
		a*=a;
		n/=2;
	}
	return result;
}
bool kt(long long i)
{
    long long x=a.length();
    long long y=b.length();
    long long maxx=max(x,y);
    long long k=(hasha[x]-hasha[x-i]*power(26,i)%1000000007+1000000007)%1000000007;
    if(hashb[i]==k) return true;
    return false;
}
int main()
{
    //freopen("in.inp","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    long long x=a.length();
    long long y=b.length();
    long long v,maxx=max(x,y);
    hasha[0]=0;
    hashb[0]=0;
    for (long long i=1;i<=x;i++) hasha[i]=(hasha[i-1]*26+int(a[i-1])+1000000007)%1000000007;
    for (long long i=1;i<=y;i++) hashb[i]=(hashb[i-1]*26+int(b[i-1])+1000000007)%1000000007;
    for (long long i=min(x,y);i>=1;i--)
    {
        if (kt(i))
        {
            cout << a;
            for (long long j=i+1;j<=y;j++) cout << b[j-1];
            return 0;
        }
    }
    cout << a << b;
}
