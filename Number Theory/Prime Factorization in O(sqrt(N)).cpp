#include<bits/stdc++.h>
using namespace std;

void primeFact(int n)
{
	bool ck = false;
	for(int i = 2; i*i<=n; i++)
	{
		if(!(n%i))
		{
			int cnt = 0;
			while(!(n%i))
			{
				cnt++;
				n /= i;
			}
			(!ck) ? printf("(%d^%d)",i,cnt), ck = true : printf("*(%d^%d)",i,cnt);
//			if(!ck)
//			{
//				printf("(%d^%d)",i,cnt);
//				ck = true;
//			}
//			else
//				printf("*(%d^%d)",i,cnt);	
		}
	}
	if(n>1)
		(!ck) ? printf("(%d^1)",n) : printf("*(%d^1)",n);	
}
int main()
{
	int n;
	scanf("%d",&n);
	
	primeFact(n);
    
	return 0;
}

