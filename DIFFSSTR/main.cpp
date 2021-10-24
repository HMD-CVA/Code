#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n;
string s;
bool check(int l)
{
    map<string,int> m;
    FOR(i,1,n-l+1)
    {
        string tam;
        FOR(j,i,i+l-1) tam+=s[j];
        if (m[tam]==1) return false;
        else m[tam]=1;
    }
    return true;
}
int main()
{
    cin >> n >> s;
    s=" "+s;
    FOR(i,1,n)
    {
        if (check(i))
        {
            cout << i;
            break;
        }
    }

}
