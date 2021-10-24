#include <bits/stdc++.h>
using namespace std;
string s,s1,T;
int deg;
int n,k;
bool kt(string s)
{
	n=s.size();
	if(n==1)
		return false;
	k=1;
	for(int i=n-1;i>=0;i--)
	{
		s1=s1+s[i];
		k++;
	}
	if(s==s1)
		return true;
	else
		return false;
}
void spl(string s)
{
	n=s.size();
	for(int i=0;i<n/2;i++)
	 	T=T+s[i];
}
int fdeg(string s)
{
	if(kt(s)==false)
		return 0;
	while(kt(s))
	{
		spl(s);
		deg++;
	}
	return deg;
}
int main()
{
	freopen("PALINDEG.INP","r",stdin);
	freopen("PALINDEG.OUT","w",stdout);
	cin>>s;
	cout<<fdeg(s);
}
