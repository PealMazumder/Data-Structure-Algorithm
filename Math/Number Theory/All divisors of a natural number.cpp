#include <bits/stdc++.h>
#define ll long long 
using namespace std; 
void Divisors(ll n) 
{ 
    vector<int> div; 
    for (ll i=1; i*i<=n; i++) 
    { 
        if (n%i == 0) 
        { 
            // If divisors are equal, take only one 
            if (n/i == i) 
                 div.push_back(i);
  
            else // Otherwise take both 
            {
            	div.push_back(i);
				div.push_back(n/i);	
			} 
        } 
    } 
    sort(div.begin(), div.end());
    for(ll x : div)
    	printf("%lld ",x);
    printf("\n");
} 
  
int main() 
{
	ll n; 
	scanf("%lld",&n);
    printf("The divisors of %lld are: \n", n); 
    Divisors(n); 
    return 0; 
} 
