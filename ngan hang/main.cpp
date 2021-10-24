#include <bits/stdc++.h>

using namespace std;

ifstream f1("nh.inp");
ofstream f2("nh.out");

int n;
int hold[1000],change[1000],ct[1000],tg[1000];

void doc()
{
    f1>>n;
    for(int i=1;i<=n;i++)
        f1>>hold[i];
}
void process()
{
    int h=1,i=1;
    do
    {
        ct[h]=i;
        i=hold[i];
        h++;
    }
    while(i!=hold[i]);
    f2<<h-1<<endl;
    for(int i=1;i<=h;i++)
        f2<<ct[i]<<" ";
}
int main()
{
    doc();
    process();
}
