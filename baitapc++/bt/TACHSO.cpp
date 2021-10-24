#include <bits/stdc++.h>
using namespace std;
string s;
string a;
int t[1000];
int n,k=0;
int string2num(string s)
{
	stringstream s2n(s);
	int x=0;
	s2n>>x;
	return x;
}
int main()
{
	cin>>s;
	n=s.size();
	for(int i=1;i<=n;i++)
	{
		if(s[i]>='0' && s[i]<='9')
			a=a+s[i];
		else
		{
			if(a!="")
			{
				t[k]=string2num(a);
				k++;
			}
			a="";
		}
	}
	for(int i=0;i<k;i++)
		for(int j=i+1;j<k;j++)
			if(t[i]>t[j])
				swap(t[i],t[j]);
	for(int i=0;i<k;i++)
		cout<<t[i]<<" ";
}

