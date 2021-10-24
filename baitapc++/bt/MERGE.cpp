#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[1000];
void doc()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
}
void Merge(int a[],int l,int k,int r)
{
	int t1=k-l+1;
	int t2=r-(k+1)+1;
	int L[t1];
	int R[t2];
	for(int i=0;i<t1;i++)
		L[i]=a[l+i];
	for(int j=0;j<t2;j++)
		R[j]=a[k+1+j];
	int i=0,j=0;
	int m=l;
	while(i<t1 && j<t2)
	{
		if(L[i]<R[j])
		{
			a[m]=L[i];
			i++;
		}
		else
		{
			a[m]=R[j];
			j++;
		}
		m++;
	}
	while(i<t1)
	{
		a[m]=L[i];
		i++;
		m++;
	}
	while(j<t2)
	{
		a[m]=R[j];
		j++;
		m++;
	}
		
}
void Mergesort(int a[],long l,long r)
{
	if(l<r)
	{
		long k=(l+r)/2;
		Mergesort(a,l,k);
		Mergesort(a,k+1,r);
		Merge(a,l,k,r);	
	}
}
int main()
{
	freopen("MERGE.inp","r",stdin);
	freopen("MERGE.out","w",stdout);
	doc();
	Mergesort(a,1,n);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
}
