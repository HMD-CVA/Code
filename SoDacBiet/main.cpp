#include <bits/stdc++.h>
using namespace std;
long long n,arr[1000001],kq=0,b[1000001],dem[1000001],size=0;
void nhap() 
{
   // freopen("in.inp","r",stdin);
	cin >> n;
    for (long long i=0;i<n;i++) 
    cin >> arr[i];
}
long long chiSo(long long *b, long long n, long long x)
{
	for(long long i=0;i<n;i++) 
    {
		if(b[i] == x) return i;
	}
	return -1;
}
void dem1(long long *arr, long long n) 
{
	for(long long i=0;i<n;i++) 
    {
		dem[i] = 0;
	}
	for(long long i=0;i<n;i++) 
    {
		long long index=chiSo(b, size, arr[i]);
		if(index==-1) 
        {
			b[size] = arr[i];
			dem[size] = 1;
			size++;
		}
        else 
        {
			dem[index]++;
		}
	}
	for(long long i=0;i<n;i++) 
    {
        if (dem[i]==1)
		{
            kq++;
        }
	}
    cout << kq << endl;
    for(long long i=0;i<n;i++) 
    {
        if (dem[i]==1)
		{
            cout << b[i] << endl; 
        }
	}
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	nhap();
	dem1(arr,n);
}
