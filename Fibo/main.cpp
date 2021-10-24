#include <bits/stdc++.h>
using namespace std;
//ifstream cin("FIBO.INP");
//ofstream cout("FIBO.OUT");
string F[1000001];
long long xl(long long n)
{
    if (n==0) cout << "0" << endl;
    if (n==1) cout << "1" << endl;
    if (n >= 2)
    {
        long long fn,f0=0,f1=1;
        for (int i=2;i<=n;i++)
        {
            fn=f0+f1;
            f0=f1;
            f1=fn;
        }
        cout << fn;
    }
}
string cong(string s1, string s2)
{
    int lens1=s1.length();
    int lens2=s2.length();
    int nho=0,kq=0,d=0;

    while (s1.length()<lens2) s1="0"+s1;
    while (lens1>s2.length()) s2="0"+s2;
    lens1=s1.length();
    string kq1(lens1,'0');

    for (int i=lens1-1;i>=0;i--)
    {
        kq=(s1[i]-48)+(s2[i]-48)+nho;
        nho=kq/10;
        kq1[i]=(kq%10)+48;
    }
    if (nho) kq1=char(nho+48)+kq1;
    return kq1;
}
void tinh()
{
    F[1]=F[2]="1";
    for (int i=3; i<=1000; i++) F[i]=cong(F[i-1],F[i-2]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long u;
    tinh();
    //u=24;
	while(cin >> u)
    {
        cout << F[u] << "\n";
        //cout << u << "\n";
    }
}

