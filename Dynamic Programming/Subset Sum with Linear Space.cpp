#include<bits/stdc++.h>
#define	mod	1000000007
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
#define	REP(i,n)	for(int i = 1; i<=n; i++)
using namespace std;
ll n, m, i, j, k, a, b, c;
void solve()
{
	int ar[100];
	int dp[100] = {0};
	cin>>n>>m;
	for(i = 1; i <= n; i++)
		cin>>ar[i];
	dp[0] = 1;
	
	for(i = 1; i<=n; i++)
	{
		for(j = m; j>=ar[i]; j--)
		{
			int need = j - ar[i];
			if(dp[j] || dp[need] == 0)
				continue;
			else dp[j] = ar[i];
		}
	}
	if(dp[m] == 0)
		cout<<"-1\n";
	else
	{
		int curr = m;
		while(curr>0)
		{
			cout<<dp[curr]<<" ";
			curr -= dp[curr];
		}
	}
	cout<<nl;
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

