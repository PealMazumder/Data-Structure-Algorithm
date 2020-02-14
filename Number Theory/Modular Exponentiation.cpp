/*
	calculating a^n % p;
*/
#include<bits/stdc++.h>
using namespace std;

long long power(int a, int n, int p)
{
	long long res = 1;
	while(n)
	{
		if(n & 1)// IF ODD
		{
			res = (res*a) % p; 
			n--; 
		}
		else
		{
			n /= 2;
			a =(a*a) % p;
		}
	}
	return res;
}
int main()
{
	int a,n,p;
	scanf("%d%d%p",&a,&n,&p);
	
	long long ans = power(a,n,p);
	printf("%lld\n",ans);
	
    return 0;
}

