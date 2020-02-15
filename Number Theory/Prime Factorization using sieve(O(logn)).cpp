#include<bits/stdc++.h>
#define	fast						ios::sync_with_stdio(false);cin.tie(0);cout.tie(NULL);
#define all(p)						p.begin(),p.end()
#define	mem(ar,val)					memset(ar, val, sizeof(ar))
#define sz(c)						(int)c.size()
#define pb(x)						push_back(x)
#define mkp(x,y)					make_pair(x,y)
#define ff						first
#define ss						second
#define ll						long long
#define nl						"\n"
#define MAX(a, b)					((a) > (b) ? (a) : (b))
#define MIN(a, b)					((a) < (b) ? (a) : (b))
#define FI						freopen("input.txt", "r", stdin);
#define FO						freopen("output.txt", "w", stdout);
using namespace std;
const int INF = 0x7f7f7f7f;
const int MX = 1000001;
int spf[MX];//Smallest prime factor
void sieve()
{
	for(int i = 1; i<MX; i++)
		spf[i] = i;
	for(int i = 4; i<MX; i += 2)
		spf[i] = 2;
	for(ll i = 3; i*i < MX; i += 2)
	{
		if(spf[i] == i)// if prime
		{
			for(ll j = i*i; j<MX; j += i)
				if(spf[j] == j)// if spf[j] is not previously marked
					spf[j] = i;
		}
	}
	
}
vector<int> getSPF(int x)
{ 
	vector<int>	pf;
	while(x != 1)
	{
		pf.pb(spf[x]);
		x /= spf[x];
	}
	return pf;
} 
int main()
{
	fast
	sieve();
	int n;
	scanf("%d",&n);
	vector<int> pf = getSPF(n);
	printf("Prime factorization for %d: ",n);
	for(int i = 0; i<pf.size(); i++)
		printf("%d ",pf[i]);
	printf("\n");
	return 0;
}


