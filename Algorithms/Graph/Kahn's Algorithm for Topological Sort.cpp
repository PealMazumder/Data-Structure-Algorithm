#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
vector<int> res;
int in[100];

bool kahns(int n)
{
	queue<int> q;
	for(int i = 1; i<=n; i++)
		if(in[i] == 0) q.push(i);
		
	while(!q.empty())
	{
		int curr = q.front();
		res.push_back(curr);
		
		q.pop();
		
		for(int node : adj[curr])
		{
			in[node]--;
			if(in[node] == 0)
				q.push(node);
		}
		
	}
	return res.size() == n;
}
int main()
{
	int n, m, x, y;
	cin>>n>>m;
	
	for(int i = 1; i<=m; i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		in[y]++;
	}
	
	if(!kahns(n))
		cout<<"Oops! Given Graph contains a cycle\n";
	else
	{
		cout<<"Topsort : ";
		for(int node : res)
			cout<<node<<" ";
	}
	
	return 0;
}
