#include <iostream>
using namespace std;
int main()
{
    int64_t n,m,k,dem=0;
    cin>>n>>m>>k;
    if(m%k==0 || n%k==0)
    {
        dem++;
        dem+=(m-n)/k;
    }
    else
        dem=(m-n)/k;
    cout<<dem;
}
