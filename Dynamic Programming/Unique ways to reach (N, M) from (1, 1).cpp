#include<bits/stdc++.h>
#define	mod	1000000007
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
#define	REP(i,n)	for(int i = 1; i<=n; i++)
using namespace std;
const ll INF = 0x7f7f7f7f;
ll n, m, i, j, k, a, b, c, tm, val, cnt = 0, ans = 0, res = 0, mn = INT_MAX, mx = 0, l ,r;
ll dp[101][101];
void solve()
{
	cin>>n>>m;
	for(i = 1; i<=m; i++) dp[n][i] = 1;
	for(i = 1; i<=n; i++) dp[i][m] = 1;
	
	for(i = n-1; i >= 1; i--)
	{
		for(j = m-1; j>=1; j--)
			dp[i][j] = dp[i+1][j] + dp[i][j+1];
	}
	
	for(i = 1; i<=n; i++)
	{
		for(j = 1; j<=m; j++)
			cout<<dp[i][j]<<" ";
		cout<<nl;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
	
	solve();

	return 0;
}

