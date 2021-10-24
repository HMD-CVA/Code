#include <bits/stdc++.h>

using namespace std;
ifstream f1("sodb.inp");
ofstream f2("sodb.out");
long long n;
void doc()
{
    f1>>n;
}
bool snt(long long a)
{
	bool kt=true;
	if(a<2) kt=false;
	for(int i=2;i<=sqrt(a);i++)
	{
		if(a%i==0)
		{
			kt=false;
		}
	}
	return kt;
}
long long tong(long long a)
{
    long long s=0;
	while(a!=0)
	{
		s+=a%10;
		a=a/10;
	}
    return s;
}
long long tich(long long a)
{
    long long sum=0;
    for(long long i=1;i<=a;i++)
    {
    	if(snt(i) && a%i==0)
    	{
    		sum+=tong(i);
    		a=a/i;
    		if(a%i==0)
    		{
    			a=a/i;
    			sum+=tong(i);
			}
		}
	}
	return sum;
}
void xl()
{
    for(long long i=n;i<=INT_MAX;i++)
    {
        if(tong(i)==tich(i))
        {
            f2<<i;
            break;
        }
    }
}
int main()
{
    doc();
    xl();
}
