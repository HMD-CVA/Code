#include <bits/stdc++.h>
using namespace std;
string s;
int dem[1000];
char t[1000];
int main()
{
	getline(cin,s);
	int k=s.size();
	for(int i=0;i<k;i++)
	{
		t[i]=s[i];
		for(int j=0;j<k;j++)
		{
			if(s[j]==s[i])
				dem[i]++;
		}
	}
	for(int i=0;i<k;i++)
	{
		for(int j=i+1;j<k;j++)
		{
			if(t[j]==t[i])
			{
				t[j]=' ';
				dem[j]=0;
			}
			if(dem[i]<dem[j])
				swap(dem[i],dem[j]);
		}
	}
	for(int i=0;i<=k;i++)
	{
		if(t[i]!=' ' && dem[i]!=0)
			cout<<t[i]<<" "<<dem[i]<<endl;
	}
}
