#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<pair<ll, ll> > primeFact(ll n)
{
	vector<pair<ll, ll> > pf;
	for(ll i = 2; i*i<=n; i++)
	{
		if(!(n%i))
		{
			int cnt = 0;
			while(!(n%i))
			{
				cnt++;
				n /= i;
			}	
			pf.push_back({i, cnt});
		}
	}
	if(n>1)
		pf.push_back({n, 1});
		
	return pf;
}
int main()
{
	ll n;
	cin>>n;
	vector<pair<ll, ll> > pf = primeFact(n);
	for(auto x : pf)
		cout<<x.first<<"^"<<x.second<<" ";
	cout<<"\n";
	return 0;
}

