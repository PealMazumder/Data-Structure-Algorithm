#include<bits/stdc++.h>
#define pb(x)						push_back(x)
using namespace std;
const int N = 87000008;
int isPrime[N>>5];
vector <int> prime;

bool check(int n,int pos)
{
	return (bool)(n & (1 << pos));
}

int Set(int n, int pos)
{
	return n = (n | (1 << pos));
}
void sieve()
{
	for(int i = 3; i*i <= N; i += 2)//avoiding even numbers
	{
		if(check(isPrime[i>>5], i&31) == 0)
		{
			for(int j = i*i; j<=N; j += 2*i)//avoiding even multiples
			{
				isPrime[j>>5] = Set(isPrime[j>>5], j&31);
			}
		}
	}
	prime.pb(2);
	for(int i = 3; i<=N; i += 2)
	{
		if(check(isPrime[i>>5], i&31) == 0)
			prime.pb(i);
	}
}
int main()
{
	sieve();
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int k;
		scanf("%d",&k);
		printf("%d\n",prime[k-1]);//Printing Kth Prime
	}
    return 0;
}

