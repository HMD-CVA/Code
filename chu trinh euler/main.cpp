#include <bits/stdc++.h>

using namespace std;

ifstream f1("euler.inp");
ofstream f2("euler.out");

int n,a[1000][1000];
int u,v,k;
queue<int> Find;
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
    int tmp;
    for(int i=1;i<=n;i++)
    {
        tmp=0;
        for(int j=1;j<=n;j++)
            tmp+=a[i][j];
        if(tmp%2!=0)
            return false;
            break;
    }
    return true;
}
void chutrinh()
{
    Find.push(1);
    while(!Find.empty())
    {
        int i=Find.front();
        for(int j=n;j>=1;j--)
        {
            if(a[i][j]>0)
            {
                Find.push(j);
                a[i][j]--;
                a[j][i]--;
                break;
            }
        }
        f2<<Find.front()<<" ";
        Find.pop();
    }
}
int main()
{
    doc();
    if(kt())
        chutrinh();
    else
        f2<<"KHONG CO CHU TRINH EULER";
}
