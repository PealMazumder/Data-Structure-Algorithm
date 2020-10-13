#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
struct edge{
	int a, b, w;
} ar[100002];
int par[10002];
bool comp(edge a, edge b)
{
	return a.w < b.w;
}
int Find(int a)
{
	if(par[a] == -1) return a;
	return par[a] = Find(par[a]);
}
void Union(int a, int b)
{
	par[a] = b;
}
void solve()
{
	int n, m;
	cin>>n>>m;
	for(int i = 0; i<m; i++)
	{
		cin>>ar[i].a>>ar[i].b>>ar[i].w;
	}
	sort(ar, ar+m, comp);
	for(int i = 1; i<=n; i++) par[i] = -1;
	int a, b, sum = 0;
	for(int i = 0; i<m; i++)
	{
		a = Find(ar[i].a);
		b = Find(ar[i].b);
		if(a != b)
		{
			sum += ar[i].w;
			Union(a, b);
		}
	}
	cout<<sum<<nl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);

//	int t;
//	cin>>t;
//	while(t--)
	    solve();

	return 0;
}


