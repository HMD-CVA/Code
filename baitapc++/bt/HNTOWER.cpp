#include <bits/stdc++.h>
using namespace std;
int n;
void Tower(int n, char a, char b, char c)
{
	if(n==1)
		cout<<a<<" => "<<c<<endl;
	else
	{
		Tower(n-1,a,c,b);
		Tower(1,a,b,c);
		Tower(n-1,b,a,c);
	}
}
void ghi()
{
	char a='coc1',b='coc2',c='coc3';
	cin>>n;
	Tower(n,a,b,c);
}
int main()
{
	freopen("HNTOWER.inp","r",stdin);
	freopen("HNTOWER.out","w",stdout);
	ghi();
}

 
