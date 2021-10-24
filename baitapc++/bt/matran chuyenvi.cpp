#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int i,j;
	int a[100][100]; int b[100][100];
	cout<<"Nhap kich thuoc cua ma tran vuong.";cin>>n;
	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<"a["<<i<<"]["<<j<<"]=";
			cin>>a[i][j];
		}
			
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			b[i][j]=a[j][i];
		}
	}
	cout<<"Ma tran chuyen vi cua a la: "; cout<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

