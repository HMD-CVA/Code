#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,st,sm;
int main()
{
	cin>>a>>b>>c>>d;
	if(b==0 || d==0)
		cout<<"-1";
	sm=b*d;
	st=(a*d)+(b*c);
	int k=(st+sm)/2;
	for(int i=k;i>=2;i--)
	{
		if(st%i==0 && sm%i==0)
		{
			st=st/i;
			sm=sm/i;
		}
	}
	cout<<st<<" "<<sm;
}

