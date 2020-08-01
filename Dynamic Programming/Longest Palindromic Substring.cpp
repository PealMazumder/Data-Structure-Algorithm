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
	ll dp[100][100] ={{0}};
	char ar[100];
	cin>>n;
	for(i = 1; i<=n; i++)
		cin>>ar[i];
	for(i = 0; i<=n; i++)
		dp[0][i] = dp[1][i] = 1;
	for(i = 2; i<=n; i++)
	{
		for(j = i; j<=n; j++)
		{
			if(ar[j] == ar[j-i+1] && dp[i-2][j-1] == 1)
				dp[i][j] = 1;
			else
				dp[i][j] = 0;
		}
	}
//	for(i = 0; i<=n; i++)
//	{
//		for(j = 0; j<=n;j++)
//			cout<<dp[i][j]<<" ";
//		cout<<nl;
//	}
	for(i = n; i>0; i--)
	{
		for(j = 1; j<=n; j++)
		{
			if(dp[i][j] == 1)
			{
				cout<<"Longest Palindromic substring lenght is: "<<i<<nl;
				return;
			}
		}
	}
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

