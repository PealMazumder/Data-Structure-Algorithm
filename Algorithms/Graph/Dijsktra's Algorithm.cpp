#include<bits/stdc++.h>
#define	inf	1000000000
using namespace std;
vector<pair<int, int> > adj[101];
int n, m, a, b, w;
void DijsktraAlgorithm()
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	vector<int> dis(n+1, inf);
	pq.push({0,1});
	dis[1] = 0;
	
	while(!pq.empty())
	{
		int curD = pq.top().first; 
		int curN = pq.top().second;
		pq.pop();
		
		for(pair<int, int> edg : adj[curN])
		{
			if(curD + edg.second < dis[edg.first])
			{
				dis[edg.first] = curD + edg.second;
				pq.push({dis[edg.first], edg.first});
			}
		}
	}
	for(int i = 1; i<=n; i++)
		cout<<dis[i]<<" ";
}
int main()
{
	
	cin>>n>>m;
	while(m--)
	{
		cin>>a>>b>>w;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}
	DijsktraAlgorithm();
	return 0;
}
/*
6 9
1 2 4
1 6 2
2 3 5
2 6 1
6 3 8
6 5 10
3 4 6
3 5 3
5 4 5
*/
