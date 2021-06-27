#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
const int N = 100010;
vector<int> adj[N], subtree(N);
void dfs(int n, int par)
{
    subtree[n] = 1;
    for(auto child : adj[n])
    {
        if(child != par)
        {
            dfs(child, n);
            subtree[n] += subtree[child];
        }
    }
}
void solve()
{
    int n, a, b, root;
    cin>>n>>root;
    for(int i = 1; i<n; i++)
    {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(root, -1);
    for(int i = 1; i <= n; i++)
        cout<<"Subtree Size of Node "<<i<<" is "<<subtree[i]<<nl;
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(NULL);
//    int t;
//    cin>>t;
//    while(t--)
        solve();
    return 0;
}


