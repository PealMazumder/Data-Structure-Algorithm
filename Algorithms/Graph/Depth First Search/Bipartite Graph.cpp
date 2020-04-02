#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
vector<int> adj[N];
vector<bool> vis(N),col(N);
bool dfs(int n, int c)
{
	vis[n] = true;
	col[n] = c;
	
	for(int child : adj[n])
	{
		if(vis[child] == false)
		{
			if(dfs(child, c^1) == false)
				return false;
		}
		else 
		{
			if(col[n] == col[child])
				return false;
		}
	}
	return true;
}
int main()
{
	int n,e;
	scanf("%d%d",&n,&e);
//    adj.assign(n,vector<int>());
//    vis.assign(n,false);
	for(int i = 0; i<e; i++)
	{
		int u, v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if(dfs(1,1))
		printf("Given graph is Bipartite\n");
	else
		printf("Given graph is not Bipartite\n");
	return 0;
}

