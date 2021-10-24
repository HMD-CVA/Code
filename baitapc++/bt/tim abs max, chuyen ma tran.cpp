#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[100][100];
	int m,n;
	cout<<"So dong: "; cin>>m;
	cout<<"So cot: "; cin>>n;
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			cout<<"a["<<i<<"]["<<j<<"]=";
			cin>>a[i][j];
		}
	}
	int max[50];
	max[0]=a[0][0];
	for (int x=0;x<m;x++)
	{
		for (int y=1;y<n;y++)
		{
			if (abs(max[0])<abs(a[x][y]))
				max[0]=a[x][y];
		}
	}
	for (int x=0;x<m;x++)
	{
		for (int y=1;y<n;y++)
		{
			if (abs(max[0])==abs(a[x][y]) && a[x][y]!=max[0])
				max[y]=a[x][y];
		}
	}
	cout<<"Phan tu co gttd lon nhat la: ";
	for(int z=0;z<=n*m-1;z++)
	{
		if (max[z]*1!=0)
			cout<<max[z]<<" ";
	}
	cout<<endl;
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (abs(a[i][j])==abs(max[0]))
			cout<<a[i][j]<<"("<<i<<","<<j<<")"<<endl;
		}
	}
}

