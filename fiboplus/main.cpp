#include <bits/stdc++.h>
using namespace std;
string f[1001];
void fibo()
{
    f[1]="1"; f[2]="2";
    for (int i=3; i<=1000; i++)
        f[i]=f[i-1]+f[i-2];
}
int main()
{
    fibo();
    string u;
    while (cin>>u)
        cout<<f[u]<<endl;
}
