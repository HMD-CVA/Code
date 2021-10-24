#include <bits/stdc++.h>
#define ll long long
#define maxx 200005
#define oo 100000009

using namespace std;

ll n, l;
struct shelt
{
    ll h;
    ll w;
};
shelt a[maxx];
void doc()
{
    cin >> n >> l;
    for(ll i = 1; i <= n; i ++)
    {
        cin >> a[i].h >> a[i].w;
    }
}
void qs(ll l,ll r)
{
	ll i = l, j = r;
	ll x = a[(l+r)/2].h;
	while(i <= j)
	{
		while(a[i].h > x) i++;
		while(a[j].h < x) j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(l < j) qs(l,j);
	if(i < r) qs(i,r);
}
void process()
{
    /*ll sum = a[1].w;
    ll hs = a[1].h;
    qs(1,n);
    for(ll i = 2; i <= n; i ++)
    {
        sum += a[i].w;
        if(sum > l)
        {
            sum = a[i].w;
            hs += a[i].h;
        }
    }
    cout << hs;*/
    ll sum = 0;
    ll hs = 0;
    ll temp = 0;
    for(ll i = 1; i <= n; i ++)
    {
        if(a[i].h < a[i].w)
        {
            hs += a[i].h;
            //cout<<hs<<" ";
        }
        else
        {
            sum += a[i].w;
            if(sum > l || a[i+1].h < a[i+1].w)
            {
                sum = a[i].w;
                temp = max(temp,a[i].h);
                hs += temp;
                //cout<<hs<<" ";
            }
            else
            {
                temp = max(temp,a[i].h);
                //cout<<temp<<" ";
            }

        }
    }
    cout<<hs;
}
main()
{
    freopen("book.inp","r",stdin);
    //freopen("book.out","w",stdout);
    doc();
    process();

}
