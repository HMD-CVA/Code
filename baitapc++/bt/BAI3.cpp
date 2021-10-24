#include <bits/stdc++.h>
using namespace std;
void inhoa(string s)
{
	int n=s.size();
	s[0]=(char)(s[0]-32);
	for (int i=1;i<n;i++)
	{
		if (s[i]==' ')
			s[i+1]=(char)(s[i+1]-32);
	}
}
int main()
{
	ifstream f1("BAI3.INP");
	ofstream f2("BAI3.OUT");
	string s;
	f1>>s;
	inhoa(s);
	f2<<s;
	return 0;
}

