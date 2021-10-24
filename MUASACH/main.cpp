#include<bits/stdc++.h>
using namespace std;
int b[105]={0};int n;
void bt(int i)
{
	n-=b[i-1];
	for(int j=b[i-1]+1;j<=n;j++)
	{
		b[i]=j;
		if(n-b[i]>0) bt(i+1);
		else
		{
			for(int k=1;k<=i;k++)
            cout<<b[k]<<" ";
			cout<<"\n";
		}
	}
	n+=b[i-1];
}
int main()
{
	cin>>n;
	bt(1);
}
/*#include<bits/stdc++.h>
using namespace std;
int x[101];
int n,k,s=0;
void ghi(int n)
{
    for(int i=1;i<=n;i++)
        cout<<x[i]<<" ";
    cout<<endl;
}
/*int sum(int x[], int n)
{
    int s=0;
    for(int i=1;i<=n;i++)
        s+=x[i];
    return s;
}
void bt(int i,int k)
{
    for(int j=x[i-1]+1;j<=n-k+i;j++)
    {
        x[i]=j;
        s=s+x[i];
        if(i==k)
        {
            //if(s==n)
            {
                ghi(i);
                cout<<s<<endl;
                s=s-x[];
            }

        }
        else
        {
            bt(i+1,k);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=n;i>=1;i--)
    {
        bt(1,i);
        s=0;
    }
}*/
