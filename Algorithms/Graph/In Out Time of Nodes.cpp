/*
  Problem :
	Given 2 nodes, find whether one node lies in the subtree of other node.
	
	Input
	7
	1 2
	2 3
	2 4
	3 5
	4 6
	4 7
	5
	1 6
	7 4
	2 5
	3 4
	7 5
	
	Output
	YES
	YES
	YES
	NO
	NO
*/

#include<bits/stdc++.h>
#define		fast			ios::sync_with_stdio(false);cin.tie(0);cout.tie(NULL);
#define		rep(i,n)			for(int i = 1; i<=n; i++)
#define		all(p)			p.begin(),p.end()
#define		mem(ar,val)			memset(ar, val, sizeof(ar))
#define		sz(c)			(int)c.size()
#define		pb(x)			push_back(x)
#define		mkp(x,y)			make_pair(x,y)
#define		ff			first
#define		ss			second
#define		gap			" "
#define		ll			long long
#define		pii         pair<int, int>
#define		pll         pair<long long int, long long int>
#define		nl			"\n"
#define		FI			freopen("input.txt", "r", stdin);
#define 	FO			freopen("output.txt", "w", stdout);
using namespace std;
const int INF = 0x7f7f7f7f;
const int M = 1e9 + 7;
const int N = 1e5+7;
vector<int> adj[N];
bool vis[N];
int in[N],out[N];
int timer = 0;
void dfs(int n)
{
	vis[n] = true;
	in[n] = ++timer;
	
	for(int child : adj[n])
	{
		if(!vis[child])
			dfs(child);
	}
	out[n] = ++timer;
}
int main()
{
//	fast
	int n;
	cin>>n;
	for(int i = 0; i<n-1; i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1);
	int q;
	cin>>q;
	for(int i = 0; i<q; i++)
	{
		int a,b;
		cin>>a>>b;
//		cout<<in[a]<<" "<<in[b]<<" "<<out[a]<<" "<<out[b]<<nl;
		if(in[a]<in[b] && out[b]<out[a] || in[b]<in[a] && out[a]<out[b])
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
    return 0;
}
