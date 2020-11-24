/*
	Given a grid of size 2 x N, find total number of ways to fill the grid using dominos
	of size 1 x 2 or 2 x 1
*/
#include<bits/stdc++.h>
#define	mod	1000000007
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
ll dp[20005];
ll totalNumberOfWay(ll pos)
{
	if(pos == 1) return 1;
	if(pos == 2) return 2;
	if(dp[pos] != -1) return dp[pos];
	
	return dp[pos] = (totalNumberOfWay(pos-1) % mod + totalNumberOfWay(pos-2) % mod) % mod;
}
void solve()
{
	ll n;
	cin>>n;
	memset(dp, -1, sizeof(dp));
	ll ans = totalNumberOfWay(n);
	cout<<ans<<nl;
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


