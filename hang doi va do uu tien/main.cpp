#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    priority_queue<int> a;
    ll n,x,y;
    string s;
    while(cin>>s)
    {
        x=a.size();
        if(s=="+" && x<15000)
        {
            cin>>n;
            a.push(n);
        }
        if(s=="-" && x>0)
        {
            y=a.top();
            ll b;
            while(b!=y)
            {
                a.pop();
                b=a.top();
            }
        }
    }
    int visit[100000];
    while(!a.empty())
    {
        if(visit[a.top()]==0)
        {
            cout<<a.top();
            visit[a.top()]=1;
            a.pop();
        }
    }

}
