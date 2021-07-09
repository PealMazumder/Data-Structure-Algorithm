#include<bits/stdc++.h>
#define ll long long
#define nl "\n"
using namespace std;
const int N = 100005;
vector<int> adj[N];
int P[N][22];
int L[N];
void dfs(int node, int par, int d)
{
    L[node] = d;
    P[node][0] = par;
    for(int child : adj[node])
        if(child != par)
            dfs(child, node, d+1);
}
void init()
{
    memset (P, -1, sizeof(P));
    dfs(1, -1, 0);
    for(int j = 1; (1 << j) < N; j++)
    {

        for(int i = 1; i < N; i++)
        {
            if(P[i][j-1] != -1)
                P[i][j] = P[P[i][j-1]][j-1];
        }
    }
}
int LCA(int a, int b)
{
    if(L[a] > L[b]) swap(a, b);
    int d = L[b] - L[a];
    while(d > 0)
    {
        int i = log2(d);
        b = P[b][i];
        d -= (1 << i);
    }
    if(a == b) return a;
    for(int i = 21; i>=0; i--)
        if(P[a][i] != -1 && P[a][i] != P[b][i])
            a = P[a][i], b = P[b][i];
    return P[a][0];
}
void solve()
{

}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
