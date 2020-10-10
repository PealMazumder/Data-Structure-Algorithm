#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
#define mx 100005
using namespace std;
vector<int>prime;
bool vis[mx];
int mu[mx];
void sieve()
{
	for(int i = 3; i*i< mx; i += 2)
	{
		if(vis[i] == false)
		{
			for(int j = i*i; j<mx; j += 2*i)
				vis[j] = true;
		}
	}
	prime.pb(2);
	for(int i = 3; i<mx; i += 2)
		if(!vis[i])
			prime.pb(i);
}
void mobius()
{
	for(int i = 1; i<mx; i++)
		mu[i] = 1;
	for(int i = 0; i<sz(prime) && prime[i]*prime[i] < mx; i++)
	{
		int x = prime[i];
		x *= x;
		for(int j = x; j<mx; j+=mx)
			mu[j] = 0;
	}
	for(int i = 0; i<sz(prime); i++)
	{
		int x = prime[i];
		for(int j = x; j<mx; j += x)
			mu[j] *= -1;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
	sieve();
	mobius();
	for(int i = 1; i<50; i++)
		cout<<mu[i]<<" ";
	cout<<nl;
	return 0;
}


