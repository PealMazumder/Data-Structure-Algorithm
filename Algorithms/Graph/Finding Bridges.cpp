#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
vector<int> adj[N];
bool vis[N];
int in[N], low[N];
int timer;
void dfs(int n, int par)
{
    vis[n] = true;
    in[n] = low[n] = timer++;

    for(int cur : adj[n])
    {  
        if(cur == par) continue;
        if(vis[cur])
            low[n] = min(low[n], in[cur]);
        else
        {
            dfs(cur,n);
            if(low[cur] > in[n])
                cout<<n<<" - "<<cur<<" is a bridge\n";
            low[n] = min(low[n],low[cur]);
        }
         
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    return 0;
}