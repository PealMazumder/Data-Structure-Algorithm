/*
  Tutorials on z_algorithm:
  		https://cp-algorithms.com/string/z-function.html
  		https://www.youtube.com/watch?v=CpZh4eF8QBw&list=PLrmLmBdmIlpvm7VaC0NTR27A_3i2sU3zd&index=3
*/

#include<bits/stdc++.h>
#define all(p)						p.begin(),p.end()
#define sz(c)						(int)c.size()
#define pb(x)						push_back(x)
#define ll						long long
#define nl						"\n"
using namespace std;
const int INF = 0x7f7f7f7f;
const int modu = 1e9 + 7;
const int N = 1e6+7;
vector<int> zFunction(string s)
{
	int len = sz(s);
	vector<int> z(len);
	
	for(int i = 1, l = 0, r = 0; i < len; i++)
	{
		if(i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while(i + z[i] < len && s[z[i]] == s[i + z[i]])
			++z[i];
		if(i + z[i] -1 > r)
			l = i, r= i + z[i] - 1;
	}
	return z;
}

int main()
{
//	fast
	string text = "pealmazumderpealpeal";
	string pattern = "peal";
	string combine = pattern + "@" + text;
	
	vector<int> v = zFunction(combine);
	for(int i = 0; i<sz(v); i++)
		cout<<v[i]<<" ";
    return 0;
}


