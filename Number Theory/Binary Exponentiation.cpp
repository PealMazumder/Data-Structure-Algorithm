/*
	In simple words, binary exponentiation is techmique 
	to calculate a^n in O(logn) time complexity
*/
#include<bits/stdc++.h>
using namespace std;

long long power(int a, int n)
{
	long long res = 1;
	while(n)
	{
		if(n & 1)// IF ODD
		{
			res *= a;
			n--; 
		}
		else
		{
			n /= 2;
			a *= a;
		}
	}
	return res;
}
int main()
{
	int a,n;
	scanf("%d%d",&a,&n);
	
	long long ans = power(a,n);
	printf("%lld\n",ans);
	
    return 0;
}

