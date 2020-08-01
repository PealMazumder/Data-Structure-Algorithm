#include<bits/stdc++.h>
#define	nl	"\n"
#define	mod	1000000007
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define mem(ar, val) memset(ar, val, sizeof(ar))
#define	REP(i,n)	for(int i = 1; i<=n; i++)
using namespace std;
const ll INF = 0x7f7f7f7f;
ll n, m, i, j, k, a, b, c, tm, val, cnt = 0, ans = 0, res = 0, mn = INT_MAX, mx = 0, l ,r;
ll dp[101][101];
ll fill(ll x, ll y)
{
	if(x>n || x<1 || y>m || y<1) return 0;
	
	if(x == n && y == m)
	{
		dp[x][y] = 1;
		return 1;
	}
	if(dp[x][y] != 1) return  dp[x][y];
	
	dp[x][y] = fill(x + 1, y) + fill(x, y+1);
	return dp[x][y];
	
}
void solve()
{
	cin>>n>>m;
	mem(dp, -1);
	
	fill(1, 1);
	
	for(i = 1; i<=n; i++)
	{
		for(j = 1; j<=m;j++)
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

