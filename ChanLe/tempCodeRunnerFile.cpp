#include<bits/stdc++.h>
using namespace std;
long long n,gia=0,d=0;
int main()
{
    cin >> n;
    if ((n/2)>100)
    {
        gia+=(n/2)*280;
        return 0;
    }
    while(n%2!=0)
    {
        n--;
        d++;
    }
    
    gia+=(n/2)*300;
    if (d<=100) gia+=d*250;
    if (d>100) gia+=d*220;
    cout << gia; 
} 