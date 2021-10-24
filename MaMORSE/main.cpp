#include <bits/stdc++.h>
using namespace std;
string T[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".---.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
string s,s1;
int c[1001],d[1001],h[1001],dp[1001],n,m;
long long power(long long a, long long n)
{
	long long result=1;
	while (n>0)
    {
		if (n%2==1) result*=a;
		a*=a;
		n/=2;
	}
	return result;
}
void nhap()
{
    freopen("in.inp","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> n;
    m=s.length();
    for (int j=1;j<=n;j++)
    {
        cin >> s1;
        c[j]=s1.length();
        for (int i=1;i<=c[j];i++) d[i]=(d[i-1]*26+int(s1[i-1])+1000000007)%1000000007;
    }
    for (int i=1;i<=n;i++)
    {
        h[i]=(h[i-1]*26+int(s[i-1])+1000000007)%1000000007;
    }
    dp[0]=1;
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            int x=h[i+c[j]-1]-h[i-1]*power(26,c[j]);
            if(x==d[j])
			dp[i+c[j]-1]+=dp[i-1];
        }
    }
    for (int i=1;i<=100;i++) cout << dp[i] <<" ";
}
int main()
{
    nhap();
}
