#include<bits/stdc++.h>
using namespace std;

const int N = 1000001;
bool vis[N];

void sieve()
{
	vis[0] = vis[1] = true;
	for(int i = 4; i<=N; i += 2)
		vis[i] = true;
	for(int i = 3; i*i<=N; i+= 2)
	{
		if(!vis[i])
		{
			for(int j = i*i; j<=N; j += 2*i)
				vis[j] = true;
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
		
		if(!vis[n]) // If n is not visited
			printf("%d is a Prime Number\n",n);
			
		else
			printf("%d is not a Prime Number\n",n);
	}
    return 0;
}
