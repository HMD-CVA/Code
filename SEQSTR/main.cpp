#include <bits/stdc++.h>
using namespace std;
int n,k,dem=0;
string s1[300001],s2;
vector<string> s[1000];
map<int,int> x;
int main()
{
    freopen("in.inp","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i=1;i<=n;i++)
    {
        cin >> s2;
        s[i].push_back(s2);
    }
    for (auto i:s[n])
    {
        for (auto j:s[n])
        if (j-i>0 && j-i<=k &&s[i].length()==s[j].length()) dem++;
    }
    cout << dem;
}
