/*
	Given a grid of size N x M, find a path from any cell in first row to any cell in last row which
	minimizes the cost.
	You can go right or down, down-right or down-left
*/
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
void solve()
{
	cin>>n>>m;
	ll ar[n+1][m+1];
	ll dp[n+2][m+2];
	
	for(i = 1; i<=n; i++)
	{
		for(j = 1; j<=m; j++)
			cin>>ar[i][j];
	}
	for(i = 0; i<=n; i++)
	{
		for(j = 0; j<=m+1; j++)
			dp[i][j] = INF;
	}
	for(i = 0; i <= m+1; i++)
		dp[n+1][i] = 0;
	for(i = n; i>0; i--)
	{
		for(j = 1; j <= m; j++)
			dp[i][j] = ar[i][j] + min(dp[i+1][j],min(dp[i+1][j+1], dp[i+1][j-1]));
	}
	for(i = 1; i<=n; i++)
	{
		for(j = 1; j<=m; j++)
			cout<<dp[i][j]<<" ";
		cout<<nl;
	}
	for(i = 1; i<=m; i++)
		mn = min(dp[1][i], mn);
	cout<<"Minimum cost is: "<<mn<<nl;
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

