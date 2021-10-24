#include <bits/stdc++.h>

using namespace std;

//ifstream f1("inp");
//ofstream f2("out");
//int n;
int a[100000];
int x,h=1;
int main()
{
    bool kt = true;
    int maxx = INT_MAX,minn = INT_MIN;
    while(cin>>x)
    {
        a[h]=x;
        h++;
    }
    if(a[2] > a[1])
        minn = a[1];
    else
        maxx = a[1];
    for(int i=3; i<=h-1; i++)
    {
        if(a[i] > a[i-1])
        {
            if(a[i] > maxx)
            {
                kt = false;
                break;
            }
            else
            {
                minn = a[i-1];
            }
        }
        else
        {
            if(a[i] < minn)
            {
                kt = false;
                break;
            }
            else
            {
                maxx = a[i-1];
            }
        }
    }
    if(kt)
        cout<<"YES";
    else
        cout<<"NO";
}
