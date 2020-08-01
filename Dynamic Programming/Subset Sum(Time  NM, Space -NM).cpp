#include<bits/stdc++.h>
#define	mod	1000000007
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
#define	REP(i,n)	for(int i = 1; i<=n; i++)
using namespace std;
//ll n, m, i, j, k, a, b, c;
void solve()
{
	int ar[100];
	int n, m;
	cin>>n>>m;
	
	for(int i = 1; i<=n; i++)
		cin>>ar[i];
	
	bool dp[n+1][m+1];
	dp[0][0] = true;
	
	for(int i = 1; i<=m; i++)
		dp[0][i] = false;
	
	for(int i = 1; i<=n; i++)
	{
		for(int j = 0; j<=m; j++)
		{
			if(j < ar[i])
				dp[i][j] = dp[i-1][j];
			else
			{
				int need = j - ar[i];
				if(dp[i-1][j] == true || dp[i-1][need] == true)
					dp[i][j] = true;
				else
					dp[i][j] = false;
			}
		}
	}
	bool ans = dp[n][m];
	if(ans == true)
		cout<<"YES\n";
	else
		cout<<"NO\n";
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

