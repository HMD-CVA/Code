#include<bits/stdc++.h>
using namespace std;
string s,kq;
int main()
{
    cin >> s;
    sort (s.begin(),s.end());
    int dem=0;
    do
    {
        dem++;
        kq+=s;
        kq+="\n";
    }
    while(next_permutation(s.begin(),s.end()));
    cout << dem << endl;
    cout << kq;
}