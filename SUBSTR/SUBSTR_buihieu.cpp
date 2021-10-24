#include <bits/stdc++.h>
using namespace std;
string s,p="";
int max1=1,max2=0;
int dp[1005][1005];
bool symm(string s,int l, int r)
{
    int k=0;
    for(int i=l;i<=(l+r)/2;i++)
    {
        if(s[i]!=s[r-k])
            return false;
        k++;
    }
    return true;
}
void tsk1()
{
    int n=s.length();
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(symm(s,i,j) && j-i+1>=max1)
                max1=j-i+1;
        }
    }
    cout<<max1<<endl;
}
void tsk2()
{
    s='@'+s;
    p='@'+p;
    int n=s.length();
    for(int i=n-1;i>=0;i--)
        p+=s[i];
    for(int i=0;i<n;i++)
    {
        dp[0][i]=0;
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i]==p[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][n];
}
int main()
{
    freopen("SUBSTR.INP","r",stdin);
    freopen("SUBSTR.OUT","w",stdout);
    getline(cin,s);
    tsk1();
    tsk2();
}
