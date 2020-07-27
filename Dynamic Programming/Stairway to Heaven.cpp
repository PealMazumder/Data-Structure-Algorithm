/*
	Problem Statement: 
				You want to reach heaven that is at the top of this staircase.
	The staircase has n steps and at each step you can climb either 1 step or 2 steps further. 
	In how many ways can you reach heaven?
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int dp[N];
int stairwayToHeaven(int n)
{
	if(n<3)
		return n;
	else if(dp[n] != 0)
		return dp[n];
		
	dp[n] = stairwayToHeaven(n-1) + stairwayToHeaven(n-2);
	
	return dp[n];
}

int main()
{
	int n;
	scanf("%d",&n);
    printf("Number of ways to reach heaven with %d stairs is %d.\n",n, stairwayToHeaven(n) );
    return 0;
}

