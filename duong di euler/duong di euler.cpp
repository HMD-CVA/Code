#include <bits/stdc++.h>

using namespace std;

ifstream f1("euler.inp");
ofstream f2("euler.out");

int n,a[1000][1000];
int u,v,k;
int x;
stack<int> Find;
void doc()
{

    f1>>n;
    while(f1>>u>>v>>k)
    {
        a[u][v]=k;
        a[v][u]=k;
    }
}
bool kt()
{
    int tmp,d=0;
    for(int i=1;i<=n;i++)
    {
        tmp=0;
        for(int j=1;j<=n;j++)
        {
            tmp+=a[i][j];
        }
        if(tmp%2!=0)
        {
            d++;
            x=i;
        }
    }
    if(d==2)
    {
        return true;
        //return x;
    }
    else
    {
        return false;
    }

}
void duongdi()
{
    int b[100000],h=1;
    if(kt() == false)
        f2<<"KHONG CO DUONG DI EULER";
    else
    {
        Find.push(x);
        while(!Find.empty())
            {
                int i=Find.top();
                for(int j=n;j>=1;j--)
                {
                    if(a[i][j]>0)
                      {
                         Find.push(j);
                         a[i][j]--;
                         a[j][i]--;
                         break;
                      }
                      else
                      {
                          b[h]=i;
                          h++;
                      }
                }
                f2<<Find.top()<<" ";
                Find.pop();
             }

         for(int i=h-1;i>=1;i--)
            f2<<b[i]<<" ";
    }
}
int main()
{
    doc();
    duongdi();
}
