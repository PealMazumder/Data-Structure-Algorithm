/*
	Resources: https://cp-algorithms.com/algebra/linear-diophantine-equation.html
	https://brilliant.org/wiki/linear-diophantine-equations-one-equation/
*/
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
ll gcd(ll a, ll b, ll& x, ll& y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	ll x1, y1;
	ll d = gcd(b, a%b, x1, y1);
	x = y1;
	y = x1 - y1 *(a/b);
	return d;
}
bool find_any_solution(ll a, ll b, ll c, ll &x, ll &y)
{
	ll x0, y0;
	ll g = gcd(abs(a), abs(b), x0, y0);
	if(c % g)
		return false;
	x = x0 * c / g;
	y = y0 * c / g;
	if(a < 0) x = -x;
	if(b < 0) y = -y;
	return true; 
}
void solve()
{
	ll a, b, c, x, y;////ax + by = c
	cin>>a>>b>>c;
	if(find_any_solution(a, b, c, x, y) == false)
		cout<<"No solution exists\n";
	else cout<<"x = "<<x<<" y = "<<y<<nl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);

	int t;
	cin>>t;
	while(t--)
	    solve();

	return 0;
}


