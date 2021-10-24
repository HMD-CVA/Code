#include <bits/stdc++.h>

using namespace std;
ifstream f1("robot.inp");
ofstream f2("robot.out");
int n;
string s;
void doc()
{
    f1>>n;
    for(int i=0;i<n;i++)
        f1>>s[i];
}
bool sdx(string s,int n)
{
    bool kt=true;
	int i=0,j=n-1;
	while(i<=j)
	{
		if(s[i]!=s[j])
		{
			kt=false;
			break;
		}
			i++;
			j--;
	}
    return kt;
}
void xuli()
{
    bool test=true;
    if(sdx(s,n)==false)
    {
        test=false;
    }
    else
    {
      for(int i=0;i<n/2;i++)
        {
            for(int j=n/2-1;j>i;j--)
            {
                if(s[i]==s[j])
                {
                    test=false;
                    break;
                }
            }
        }
    }
    if(test==true) f2<<"CO";
    else f2<<"KHONG";
}
int main()
{
    doc();
    xuli();
}
