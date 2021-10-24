#include <bits/stdc++.h>
#define ll long long
#define str string
#define maxx 200005

using namespace std;
ll n;
str a[maxx];
str s1, s2;
void doc()
{
    cin >> n;
    for (ll i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
}
bool xl(str s1, str s2)
{
    ll d = 0;
    for(ll i = 0; i < s1.size(); i ++)
    {
        for(ll j = 0; j < s2.size(); j ++)
        {
            if(s1[i] == s2[j])
            {
                s1.erase(1,i);
                s2.erase(1,j);
                d++;
            }
            if(d == s1.size() || d == s2.size())
            {
                //cout<<"1";
                break;
                //kt = 1;
            }
        }
    }
    if(d != s1.size() && d != s2.size())
        return false;
    else
        return true;
}
int main()
{
    doc();
    ll d = 0;
    for(ll i = 1; i < n; i ++)
    {
        for(ll j = i+1; j <= n; j ++)
        {
            if(a[i] == a[j])
            {
                d+=2;
            }
            else
            {
                if(xl(a[i],a[j]))
                    d++;
            }
        }
    }
    cout<<d;
}
