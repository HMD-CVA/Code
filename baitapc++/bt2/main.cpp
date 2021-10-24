#include <bits/stdc++.h>
using namespace std;
bool MTV(int A[][100], int n,int m)
{
	if (n==m)
	return true;
	else
	return false;
}
bool MTC(int A[][100], int n)
{
    bool kt;
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if (i!=j && A[i][j]==0)
                kt=true;
            else
                kt=false;
        }
	}
	return kt;
}
int main()
{
	int x,dem1=0,dem2=0,n,m;
	int A[100][100];
	ifstream file1("INPUT.txt");
	ofstream file2("OUTPUT.txt");
	file1>>x;
	while(!file1.eof())
	{
		file2<<x<<" "; dem2++;
		if (file1.get()==10)
		{
			file2<<endl;
			dem1++;
		}
		file1>>x;
	}
	n=dem1;
	m=dem2/dem1;
	if(MTV(A,n,m) && MTC(A,n))
        file2<<"Day la ma tran duong cheo.";
        else
            file2<<"Day khong phai ma tran duong cheo.";
	if (MTV(A,n,m)==false)
	file2<<"Day khong phai la ma tran duong cheo.";
	return 0;
}
