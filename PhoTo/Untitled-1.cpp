#include<bits/stdc++.h>
using namespace std;
long long n,n1,gia=0,d=0,l,l1;
int main()
{
    cin >> n1;
    int n=n1;
    int k=n%2;
    if (k==0)
    {
        l=n1/2;
        l1=l;
        if (l%2!=0);
        {
            while(l1%2!=0)
            {
                l1--;
                d++;
            }
            if (l1>100) gia=(l1*280)+d*250;
        }
        else
        {
            if((l1/2)>100) gia=(l*280);
            else  gia=(l*300);
        }
    }
    else
    {
        while(n%2!=0)
        {
            n--;
            d++;
        }
        if (n>100) gia=(n*280)+d*250;
        if (n<=100)gia=(n*300)+d*250;
    }
    cout << gia;
}
