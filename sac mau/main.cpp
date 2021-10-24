#include <bits/stdc++.h>

using namespace std;

int a,b;
string s1, s2;
int doc(string s)
{
    int x;
    if(s == "Red")
        x = 1;
    if(s == "Orange")
        x = 2;
    if(s == "Yellow")
        x = 3;
    if(s == "Green")
        x = 4;
    if(s == "Blue")
        x = 5;
    if(s == "Violet")
        x =6;
    return x;
}
void xl(int n)
{
    if(n == 1)
        cout<<"Red";
    if(n == 2)
        cout<<"Orange";
    if(n == 3)
        cout<<"Yellow";
    if(n == 4)
        cout<<"Green";
    if(n == 5)
        cout<<"Blue";
    if(n == 6)
        cout<<"Violet";
}
void process(string s1, string s2)
{

    a = doc(s1);
    b = doc(s2);
    if(abs(a-b) == 1 || abs(a-b) == 5)
        cout<<"Adjacent";
    else
    {
        if(a == b)
           cout<<"Same";
        else
        {
            if(abs(a-b) == 3)
                cout<<"Complementary";
            else
            {
                if(abs(a-b) == 2)
                {
                   int c = min(a,b);
                   xl(c+1);
                }
                else
                    cout<<"None";
        }

        }

    }

}
int main()
{
    freopen("color.inp","r",stdin);
    freopen("color.out","w",stdout);
    cin>>s1>>s2;
    process(s1,s2);
}
