/*
	Given a grid of size N x M, Find a path from cell (1, 1) to (N, M) which minimizes the cost.
	You can go right or down only.
*/
#include<bits/stdc++.h>
#define	mod	1000000007
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
#define	REP(i,n)	for(int i = 1; i<=n; i++)
const ll INF = 0x7f7f7f7f;
using namespace std;
ll n, m, i, j, k, a, b, c, tm, val, cnt = 0, ans = 0, res = 0, mn = INT_MAX, mx = 0, l ,r;
void solve()
{
	cin>>n>>m;
	ll ar[n+1][m+1];
	for(i = 1; i<=n; i++)
		for(j = 1; j<=m; j++)
			cin>>ar[i][j];
			
	for(i = 0; i <= n; i++)	
		ar[i][0] = INF;
	for(i = 1; i <= m; i++)
		ar[0][i] = INF;
	ar[0][1] = ar[1][0] = 0;
	
	for(i = 1; i<=n; i++)
		for(j = 1; j<=m; j++)
			ar[i][j] = ar[i][j] + min(ar[i-1][j], ar[i][j-1]);
			
			
	cout<<"Minimum cost is: "<<ar[n][m]<<nl;
	
//	for(i = 1; i<=n; i++)
//	{
//		for(j = 1; j<=m; j++)		
//			cout<<ar[i][j]<<" ";
//		cout<<nl;
//	}
	
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

