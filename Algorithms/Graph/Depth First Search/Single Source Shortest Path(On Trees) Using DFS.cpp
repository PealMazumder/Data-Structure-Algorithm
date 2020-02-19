/*
	Sample Input:
		6 5
		1 2
		2 3
		2 4
		4 5
		4 6
		2
		
	output:
		1 0 1 1 2 2
		
*/

#include<bits/stdc++.h>
#define pb(x)						push_back(x)
using namespace std;
vector<vector<int> > adj;
vector<bool> vis;
vector<int> dis;
void dfs(int v,int d)
{
	vis[v] = true;
	dis[v] = d;
	for(int i = 0; i<adj[v].size(); i++)
	{
		int child = adj[v][i] ;
		if(!vis[child])
			dfs(child,dis[v]+1);
	}
}
void print(int n,int s)
{	
	for(int i = 1; i<=n; i++)
		printf("Shortest Path between %d and %d is: %d\n",s,i,dis[i]);
}
int main()
{
	int n, e;
	scanf("%d%d",&n,&e);
	adj.assign(n+1,vector<int>());
	vis.assign(n+1,false);
	dis.assign(n+1,0);
	for(int i = 0;i<e; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	int source;
	scanf("%d",&source);
	
	dfs(source,0);
	
	print(n,source);
    return 0;
}


