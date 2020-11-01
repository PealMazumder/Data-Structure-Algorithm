/*
	Tutorials: http://www.shafaetsplanet.com/?p=2531
	https://cp-algorithms.com/graph/strongly-connected-components.html
	https://www.youtube.com/watch?v=D-f-Zi2JfgM&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=39 
*/

#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
vector<int> g[10001], gr[10001];
vector<int> order, scc;
bool vis[10001];

void dfs1(int node)
{
	vis[node] = 1;
	
	for(int child : g[node])
		if(vis[child] == 0)
			dfs1(child);
	order.pb(node);
}
void dfs2(int node)
{
	vis[node] = 1;
	for(int child : gr[node])
		if(vis[child] == 0)
			dfs2(child);
	scc.pb(node);
}
void solve()
{
	int n, m, a, b;
	cin>>n>>m;
	for(int i = 1; i<=n; i++)
		g[i].clear(), gr[i].clear(), vis[i] = 0;
	order.clear();
	
	for(int i = 1; i<=m; i++)
	{
		cin>>a>>b;
		g[a].pb(b);
		gr[b].pb(a);
	}
	
	for(int i = 1; i<=n; i++)
		if(vis[i] == 0) dfs1(i);
	
	for(int i = 1; i<=n; i++) vis[i] = 0;
	
	for(int i = 1; i<=n; i++)
	{
		if(vis[order[n-i]] == 0)
		{
			scc.clear();
			dfs2(order[n-i]);
			cout<<"----------scc----------\n";
			for(int node : scc)
				cout<<node<<" ";
			cout<<nl;
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


