#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n,k,kq,m,dem=0;
   cin >> n;
   while(n!=0)
   {
       dem++;
       k=n;
       kq=-1;
       while(k!=0)
       {
           m=k%10;
           k/=10;
           kq=max(kq,m);
       }
       n-=kq;
   }
   cout << dem;
}
