#include <bits/stdc++.h>
using namespace std;
long long stolen(long long  n)
{
	long long r=123456789;
    if (n==0) 
		return 1;
    else
    {
        long long t=stolen(n/2);
        if(n%2==0) 
			return (t*t)%r;
        else 
			return (t*t*x)%r;
    }
}
int main()
{
    long long n;
    cin>>n;
    cout<<stolen(n-1);
}
    
