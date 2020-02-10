#include<bits/stdc++.h>
using namespace std;

const int N = 1000001;
bool isPrime[N];

void sieve()
{
	for(int i = 2; i<=N; i++) 
		isPrime[i]  = true;
		
	isPrime[0] = isPrime[1] = false;
	
	for(int i = 2; i*i<=N; i++)
	{
		if(isPrime[i])
		{
			for(int j = i*i; j<=N; j += i)
				isPrime[j] = false;
		}
	}
}
int main()
{
	sieve();
	
	int query;
	scanf("%d",&query);
	
	while(query--)
	{
		int n;
		scanf("%d",&n);
		
		if(isPrime[n])
			printf("%d is a Prime Number\n",n);
			
		else
			printf("%d is not a Prime Number\n",n);
	}
    return 0;
}

