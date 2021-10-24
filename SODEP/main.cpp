#include <bits/stdc++.h>
using namespace std;
int n,k=10;
int summ(int n)
{
    int ln=0,s=0;
    while(n!=0)
    {
        ln=n%10;
        s+=ln*ln;
        n=n/10;
    }
    return s;
}
bool prime(int n)
{
    if(n<2)
        return false;
    if(n==2)
        return true;
    else
    {
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
}
int main()
{
    cin>>n;
    int i=1;
    while(i<=n)
    {
        k++;
        if(prime(summ(k)))
            i++;
    }
    cout<<k;
}
