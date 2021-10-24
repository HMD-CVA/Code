#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[100][100];
	int n,s,r=0;
	int i,j,k,l;
	int x=0,y=0;
	cout<<"Nhap kich thuoc cua ma tran: ";cin>>n;
	s=pow(n,2);
	while (r!=s)
	{
		for(i=0;i<n;i++)
		{
			r++;
			a[x][i]=r;
		}
		i++; x++;
		for(j=1;j<n;j++)
		{
			r++;
			a[j][n-1]=r;
		}
		j++;
		for(k<n-1;k>=0;k--)
		{
			r++;
			a[n-1][k]=r;
		}
		k--;
		for(l<n-1;l>=1;l--)
		{
			r++;
			a[l][y]=r;
		}
		l--; y--;
		n-=2;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}


