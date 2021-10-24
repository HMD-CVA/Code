#include <bits/stdc++.h>
using namespace std;
int n,m,s;
bool visited[1000];
int a[1000][1000];
int u,v;
queue <int> q;
void doc()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;i++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		visited[i]==false;
}
void DFS(int u)
{
	cout<<u<<endl;
	visited[u]==true;
	for(int v=1;v<=n;v++)
	{
		if(a[u][v]==1 && visited[v]==false)
		DFS(v);
	}
}
/*void BFS(int s)
{
	q.push(s);
	visited[s]==true;
	while(!q.empty)
	{
		int u=q.front();
		q.pop();
		cout<<u<<endl;
		for(int v=1;v<=n;v++)
		{
			if(a[u][v]==1 && visited[v]==false)
			visited[v]==true;
			q.push(v);
		}
	}
}*/
int main()
{
	/*freopen("Bai1.inp","r",stdin);
	freopen("Cau1.out","w",stdout);*/
	doc();
	DFS(1);
	/*BFS(1);*/
}
