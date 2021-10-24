#include<bits/stdc++.h>
using namespace std;
string x,y,kq;
int main()
{
    cin >> x >> y;
    int n=x.length();
    int m=y.length();
    int savea[10000],saveb[10000];
    for (int i=0;i<n;i++)
    {
        savea[int(x[i]-97)]=1;
    }
    for (int i=0;i<m;i++)
    {
        saveb[int(y[i]-97)]=1;
    }
    for (int i=0;i<26;i++)
    {
        if (savea[i]==saveb[i] && savea[i]==1 )
        {
            cout << char(i+97) << "\n";
        }
    }
}