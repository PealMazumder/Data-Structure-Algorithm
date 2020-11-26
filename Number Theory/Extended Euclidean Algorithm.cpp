#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
ll ext_gcd(ll a, ll b, ll& x, ll& y){
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
void solve()
{
	ll a, b;
	while(scanf("%lld %lld", &a, &b) == 2)
	{
		ll x, y, gcd;
		gcd = ext_gcd(a, b, x, y);
		printf("%lld %lld %lld\n", x, y, gcd);
	}
}
int main()
{
//	int t;
//	scanf("%d", &t);
//	while(t--)
	solve();

	return 0;
}


