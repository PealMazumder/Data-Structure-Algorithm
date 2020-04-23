#include<bits/stdc++.h>
#define pb(x)					push_back(x)
#define ll						long long
#define nl						"\n"
using namespace std;
const int N = 100000;
vector<int> adj[N];
vector<bool> vis(N);
using namespace std;
void bfs(int n)
{
	cout<<n<<" ";
	queue <int> q;
	vis[n] = true;
	q.push(n);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		
		for(int u : adj[v])
		{
			if(!vis[u])
			{
				vis[u] = true;
				q.push(u);
				cout<<u<<" ";
			}
		}
	}
}
int main()
{
	int node,edge;
	scanf("%d %d",&node,&edge);
//    adj.assign(n,vector<int>());
//    vis.assign(n,false);
	for(int i = 0; i<edge; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	bfs(1);
    return 0;
}

