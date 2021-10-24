#include <bits/stdc++.h>
#define ll long long

using namespace std;
//ifstream f1("snt.inp");
//ofstream f2("snt.out");

ll a;
void nhap()
{
    cin>>a;
}
bool snt(int n)
{
	bool kt=true;
	if(n<2)
	{
		kt=false;
    }
	else
	{
		for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			kt=false;
			break;
		}
	}
	}

	return kt;
}
void process()
{
    int b[10000],c[10000];
    ll h=1,x=0;
    for(ll i=1;i<=a-4;i++)
    {
        if(snt(i))
        {
            c[h]=i;
            h++;
        }
    }
    ll i=1;
    while(c[i]<=a/3)
    {
        a-=c[i];
        ll j=i;
        while(c[j]<=a/2)
        {
            a-=c[j];
            if(snt(a))
            {
                cout<<c[i]<<" "<<c[j]<<" "<<a<<endl;
            }
            a+=c[j];
            j++;
        }
        a+=c[i];
        i++;
    }
}
/*void process()
{
    int b[10000],c[10000];
    ll h=1,x=0,k=1;
    for(ll i=1;i<=a-4;i++)
    {
        if(snt(i))
        {
            c[h]=i;
            h++;
        }
    }
    for(ll i=h-1;i>=1;i--)
    {
        for(ll j=h-1;j>=1;j--)
        {
            x=a-c[i]-c[j];
            if(x>0)
            {
                if(snt(x))
                {
                   b[k]=x;
                   k++;
                   b[k]=c[i];
                   k++;
                   b[k]=c[j];
                   k++;
                }
            }
            else
                break;
        }
    }
    for(ll i=1;i<k;i++)
    {
        cout<<b[i]<<" "<<b[i+1]<<" "<<b[i+2]<<endl;
        i+=2;
    }
}*/
/*void process()
{
    int b[10000];
    //ll c=0,h=1;
    if(a<=5)
        cout<<"-1";
    else
    {
         if(snt(a-4)) cout<<"2"<<" "<<"2"<<" "<<a-4;
   else if(snt(a-5)) cout<<"2"<<" "<<"3"<<" "<<a-5;
   else
   {
       for(ll i=2;i<=a;i++)
      {
       if(snt(i))
       {
           for(ll j=3;j<=a;j++)
           {
               if(snt(j) && snt(a-i-j))
               {
                   b[1]=i;
                   b[2]=j;
                   b[3]=a-j-i;
                   break;
               }
               j+=1;
           }
        }

       }
   int d=0;
   for(int i=1;i<=3;i++)
   {
       if(b[i]<2)
        d++;
   }
   if(d>0) cout<<"-1";
   else
    cout<<b[3]<<" "<<b[2]<<" "<<b[1];

    }
    }
}*/
int main()
{
    nhap();
    if(a<=5) cout<<"-1";
    else
        process();

}
