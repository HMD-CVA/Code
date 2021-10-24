#include <bits/stdc++.h>

using namespace std;

//ifstream f1("ami.inp");
//ofstream f2("ami.out");

string s;
void nhap()
{
    cin>>s;
}
bool sdx(string a)
{
	bool ktt=true;
	long long n=a.size()-1;
	for(long long i=0;i<=n;i++)
	{
		if(a[i]!=a[n-i] && n-i>i)
		{
			ktt=false;
		}
	}
	return ktt;
}
void process()
{

    bool kt=true;
    long long n=s.size()-1;
    if(n==0)
        cout<<"1";
    else
    {
        if(s[0]==s[n] || s[0]==s[1])
        {
            if(s[0]==s[1])
        {
            for(long long i=1;i<=n;i++)
            {
                if(s[i]==s[i]+1)
                    i++;
                else if(s[i]==s[i-1] && s[i]!=s[i+1])
                    i++;
                else
                {
                    kt=false;
                    break;
                }
            }
        }
        if(s[0]==s[n])
        {
            if(s[1]!=s[2])
            {
                 kt=false;
            }
            for(long long i=2;i<=n-1;i++)
            {
                if(s[i]==s[i+1])
                    i++;
                else if(s[i]==s[i-1] && s[i]!=s[i+1])
                    i++;
                else
                    kt=false;
            }
        }
     if(kt==true) cout<<"1";
     else cout<<"0";
        }
        else
            cout<<"0";
    }


}
int main()
{
    nhap();
    if(sdx(s)) cout<<"1";
    else
    {
        process();
    }

}
