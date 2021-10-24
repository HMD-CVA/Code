#include <bits/stdc++.h>
using namespace std;
priority_queue <int, vector<int>, greater<int> > pq;
int n,a,b,s,t;
void doc()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		pq.push(a);
	}
}
void xuli()
{
	while(!pq.empty())
	{
		a=pq.top();
		s=s+a;
		pq.pop();
		b=pq.top();
		t=t+a+b;
	}
	cout<<s<<" "<<t-b;
}
int main()
{
	doc();
	xuli();
}
