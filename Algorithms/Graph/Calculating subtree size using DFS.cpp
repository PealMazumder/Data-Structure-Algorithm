#include<bits/stdc++.h>
#define pb(x)					push_back(x)
#define sz(c)						(int)c.size()
#define ll						long long
#define nl						"\n"
#define pii						pair<int, int>
using namespace std;
const int N = 2e5+5;
vector<int> adj[N];
vector<bool> vis(N);
int subtsize[N];
int dfs(int n, int d)
{
	vis[n] = true;
	int cnt = 1;
	for(int u : adj[n])
	{
		if(!vis[u])
		{
			int c =	dfs(u, d+1);
			cnt += c;
		}
	}
	return subtsize[n] = cnt;
}
int main()
{
	int n, k;
	scanf("%d",&n);
	for(int i = 0; i<n-1; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,1);
	for(int i = 1; i<=n; i++)
		printf("%d ",subtsize[i]);
	printf("\n");
    return 0;
}

