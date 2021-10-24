#include <bits/stdc++.h>

using namespace std;

int n;
int a[100000],visit[100000];
int main()
{
    bool kt = true;
    int maxx = INT_MAX,minn = INT_MIN;
    cin>>n;
    cin>>a[1]>>a[2];
    if(a[2] > a[1])
        minn = a[1];
    else
        maxx = a[1];
    for(int i=3; i<=n; i++)
    {
        cin>>a[i];
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
        cout<<"1";
    else
        cout<<"0";
}
