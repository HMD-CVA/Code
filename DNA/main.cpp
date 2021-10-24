#include <bits/stdc++.h>
using namespace std;
int them=0,sua=0,xoa=0,n,m,k;
string s1,s2;
int main()
{
    cin >> s1 >> s2;
    n=s1.length();
    m=s2.length();
    for (int i=1;i<=n;i++)
    {
        if (s1[i]!=s2[i] && n<m) them++;
        if (s1[i]!=s2[i] && n==m) sua++;
        if (s1[i]!=s2[i] && n>m) xoa++;
    }
    k=them+sua+xoa;
    //cout << k ;
    if (k<=2) cout << "Yes";
    else cout << "No";
}
