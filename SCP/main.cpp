#include <iostream>

using namespace std;

int main()
{
    int n,d=0,k,a[10000]={0};
    cin >> n >> k;
    for (int i=1;i<=n;i++)
    for (int j=2;j<=k;j++)
    {
        if(i%j!=0) a[i]=1;
        else a[i]=0;
    }
   for (int i=1;i<=n;i++) cout << a[i] << " ";
}
