#include <bits/stdc++.h>
#define ll long long

using namespace std;
//ifstream f1("SUBSTR.INP");
//ofstream f2("SUBSTR.OUT");

string s;
int f[1005][1005];
void doc()
{
    getline(cin,s);
}
bool xdx(string a,int b, int c)
{
    bool kt=true;
    for(int i=b;i<=c;i++)
    {
        if(s[i]!=s[c])
        {
            kt=false;
            break;
        }
        c--;
    }
    return kt;
}
/*void xl()
{
    int maxsum=0;
    for (int i=0; i<s.length();)
    {
        int j=i;
        while (i<s.length()&& s[i+1]==s[i]) i++;
        i++;
        int k=i-1;
        while (k<s.length()&& j>0 &&s[k+1]==s[j-1])
        {
            k++;
            j--;
        }
        maxsum=max(maxsum,k-j+1);
    }
    cout<<maxsum;
    cout<<endl;
}*/
void xl()
{
    int n=s.length();
	int maxx=0;
    for(int k=0; k<n-1; k++)
    {
        for(int h=1;h<=n-1;h++)
        {
            if(xdx(s,k,h))
            {
                maxx=max(maxx,h-k+1);
            }
        }
    }
    cout<<maxx<<endl;
}
void process()
{
    string b;
    int n=s.length();
    int j=s.length()-1;
    while(j>=0)
    {
        b+=s[j];
        j--;
    }

    int maxx=0;
    for(int k=1; k<=n-1; k++)
    {
        if(xdx(s,0,k))
            maxx=max(maxx,k+1);
        if(xdx(s,k+1,n-1))
            maxx=max(maxx,n-1-k);
    }
    //cout<<maxx<<endl;
    s=" "+s;
    b=" "+b;
    //n=s.length();
   for(int k=1; k<=n; k++)
   {
       f[0][k]=0;
       f[k][0]=0;
   }
   for(int h=1; h<=n; h++)
   {
       for(int k=1; k<=n; k++)
       {
           if(b[h]==s[k])
           {
               f[h][k]=f[h-1][k-1]+1;
           }
           else
           {
               f[h][k]=max(f[h-1][k],f[h][k-1]);
           }
       }
   }
   cout<<f[n][n];
}
int main()
{
    freopen("SUBSTR.INP","r",stdin);
    freopen("SUBSTR.OUT","w",stdout);
    doc();
    xl();
    process();
}
