#include <bits/stdc++.h>
using namespace std;
bool amstrong (int a)
{
	int x,y,z;
	x=a/100;
	y=a/10-10*x;
	z=a-(100*x)-(10*y);
	int k=pow(x,3)+pow(y,3)+pow(z,3);
	if (k==a)
		return true;
		else 
			return false;
}
int main()
{
	ofstream f2("BAI1.OUT");
	int i;
	for(i=100;i<=999;i++)
	{
		if (amstrong(i))
			f2<<i<<" ";
	}
	return 0;
}
