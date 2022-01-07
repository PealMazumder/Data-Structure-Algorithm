#include<bits/stdc++.h>
#define pb(x)						push_back(x)
using namespace std;
const int N =  100005;
vector<vector<int> > adj;
vector<bool> vis;
bool dfs(int node, int par)
{
	vis[node] = true;
	for(auto child : adj[node])
    {
        if(!vis[child])
        {
            if(dfs(child, node) == true)
                return true;
        }
        else if(child != par)
            return true;
    }
	return false;
}
int main()
{
	int n, e, u, v;
	scanf("%d%d",&n, &e);
	adj.assign(n+1,vector<int>());
	vis.assign(n+1,false);
	for(int i = 0;i<e;i++)
	{
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	if(dfs(u, -1))
        printf("Yes\n");
    else printf("No\n");

    return 0;
}
