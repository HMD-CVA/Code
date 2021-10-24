#include <bits/stdc++.h>
using namespace std;
int n;
int a[50005];
bool checking()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if((a[i]>a[i-1] && a[i]>a[i-2]) || (a[i]<a[i-1] && a[i]<a[i-2]))
            i+=0;
        else
            return false;
    }
    return true;
}
int main()
{
    freopen("BSTCHECKING.INP","r",stdin);
    freopen("BSTCHECKING.OUT","w",stdout);
    if(checking)
        cout<<"yes";
    else
        cout<<"no";
}
