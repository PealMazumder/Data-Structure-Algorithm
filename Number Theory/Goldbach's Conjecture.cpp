/*
	For any intege n (n>=4) there exit two prime numbers p1 and p2 such that p1 + p2 = n.
	In this code, we will find all such pairs.
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 33333;
vector<pair<int, int> > pairs;
bool flag[N];
void sieve()
{
	flag[0] = flag[1] =  true;
	for(int i = 4; i<=N; i+=2)
		flag[i] = true;
	for(int i = 3; i*i<=N; i+=2)// avoiding even numbers
		if(!flag[i])
		{
			for(int j = i*i; j<=N; j += 2*i) // avoiding even multiples
				flag[j] = true;
		}
}
void findPairs(int n)
{
	for(int i = 2; i<=n/2; i++)
	{
		if(!flag[i] && !flag[n-i])
			pairs.push_back(make_pair(i, n-i));
	}
}
void printPairs()
{
	for(auto x : pairs)
		cout<<x.first<<" "<<x.second<<"\n";
}
int main()
{
	sieve();
	int n;
	scanf("%d",&n);
	findPairs(n);
	printPairs();
	return 0;
}
