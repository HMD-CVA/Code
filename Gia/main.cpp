#include <bits/stdc++.h>
using namespace std;
int n,a[1000],kt[100];
void nhap()
{
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    memset(kt,0,100);
    for (int i=1;i<=n/2;i++)
    {
        if (kt[i]==0)
        {
            cout << a[i] << endl;
            kt[i]=1;
        }
        t=4*a[i]/3;

    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
