#include <bits/stdc++.h>
using namespace std;
int hasha[1000],hashb[1000];
string a,b;
int power(int a, int b)
{
    int result=1;
    for(int i=1;i<=b;i++) result*=a;
    return result;
}
int main()
{
    freopen("in.inp","r",stdin);
    cin >> a >> b;
    int x=a.length();
    int y=b.length();
    for (int i=0;i<y;i++) hashb[i]=(hashb[i]+int(b[i])*power(26,y-i))%1000000007;
    for (int i=0;i<x;i++) hasha[i]=(hasha[i-1]*26+int(a[i]))%1000000007;

    for (int i=0;i<y;i++) cout << hashb[i] <<"  ";
    cout << endl;
    for (int i=0;i<x;i++) cout << hasha[i] <<" ";

}
