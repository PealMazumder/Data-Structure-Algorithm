#include<bits/stdc++.h>
using namespace std;
int SOD(int n)
{
	int sum = 1,p;
	for(int i = 2; i*i<=n; i++)
	{
		if(n%i == 0)
		{
			p = i;
			while(n%i == 0)
			{
				p *= i; 
				n/=i;
			}
			sum *= (p-1)/(i - 1);
		}
	}
	if(n>1)
	{
		p = n * n;
		sum *= (p-1)/(n - 1);
	}
	return sum;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("Sum of Divisors of %d is : ",n);
	printf("%d\n",SOD(n));
	return 0;
}
