```
Iterator lower_bound (Iterator first, Iterator last, const val)

Iterator upper_bound (Iterator first, Iterator last, const val)

lower_bound
returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’. (Greater or equal)
upper_bound
returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’.
```

```
int comp(pair<int, int> a, pair<int, int> b)
{
	if(a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}
```

```
/// Modular arithmetic
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }  /// When MOD is prime.
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
```

```
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// *os.find_by_order(k) ; kth element
//  os.order_of_key(k) ; number of element less than k
```

```
string digit="0123456789";
string small="abcdefghijklmnopqrstuvwxyz";
string capital="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};

```

```

/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
bool isPowerOfTwo (ll x) {return x && (!(x&(x-1)));}
int Toggle(int N, int pos){return N ^= 1 << pos;}
/*------------------------------------------------*/
```



### <u>Template</u>

```
#include<bits/stdc++.h>
#define		nl				"\n"
#define		mod				1000000007
#define		sz(c)			(int)c.size()
#define		pb				push_back
#define		f				first
#define		s				second
#define		mkp				make_pair
#define		ll				long long
#define		pii				pair<int, int>
#define 	pll				pair<ll, ll>
#define 	vll				vector<ll>
#define 	vi				vector<int>
#define		no				cout<<"NO\n"
#define		yes				cout<<"YES\n"
#define		one				cout<<"1\n"
#define		mone			cout<<"-1\n"
#define		gcd(a, b)		__gcd(a, b)
#define		total_bit(a)	__builtin_popcount(a)
#define		lcm(a, b)		((a)*((b)/gcd(a,b)))
#define		REP(i,n)		for(int i = 0; i<n; i++)
#define		all(p)			p.begin(),p.end()
#define		mem(ar,val)		memset(ar, val, sizeof(ar))
#define 	UNIQUE(a)		sort(all(a)); a.erase(unique(all(a)), a.end())
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const double pi = acos(-1.0);
const ll INF = 1000000000000000000;
const int N = 1e6+7;

void solve()
{
	ll n, i, j;
	cin>>n;
	ll ar[n];
	for(i = 0; i < n; i++){
		cin>>ar[i];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
```

#### <u>Binary Search</u>

```
int binarySearch(vector<int> &ar, int target){
  int left = 0, right = ar.size() - 1;
  while(left <= right)
  {
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    
    if(ar[mid] == target)
    	return mid;
    else if(ar[mid] < target) 
		left = mid + 1;
    else
		right = mid - 1;
		
  }
  return -1;
}
```



### <u>Number Theory</u>

#### Primes:

```
vector<ll> prime;
bool vis[N];
void sieve()
{
	for(ll i = 3; i*i<=N; i+=2)
	{
		if(!vis[i])
		{
			for(ll j = i*i; j<=N; j += 2*i)
				vis[j] = true;
		}
	}
	prime.push_back(2LL);
	for(ll i = 3; i<N; i += 2)
		if(!vis[i]) prime.push_back(i);
}
```

```
const int N = 1000001;
bool vis[N];

void sieve()
{
	vis[0] = vis[1] = true;
	for(int i = 4; i<=N; i += 2)
		vis[i] = true;
	for(int i = 3; i*i<=N; i+= 2)//avoiding even numbers
	{
		if(!vis[i])
		{
			for(int j = i*i; j<=N; j += 2*i)//avoiding even multiples
				vis[j] = true;
		}
	}
}
```

#### <u>Sum Of Divisors</u>

```
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
```

#### <u>Number of Divisor</u>

```
const ll N = 1e6 + 1;
vector<ll> prime;
bool vis[N];
void sieve()
{
	for(ll i = 3; i*i<=N; i+=2)
	{
		if(!vis[i])
		{
			for(ll j = i*i; j<=N; j += 2*i)
				vis[j] = true;
		}
	}
	prime.push_back(2LL);
	for(ll i = 3; i<N; i += 2)
		if(!vis[i]) prime.push_back(i);
}
ll NOD(ll n)
{
	ll ret = 1;
	ll root = sqrt(n);
	for(ll i = 0;i<prime.size() && prime[i]<=root; i++)
	{
		if(n%prime[i] == 0)
		{
			int cnt = 1;
			while(n%prime[i] == 0)
			{
				cnt++;
				n/=prime[i];
			}
			ret *= cnt;
			root = sqrt(n);
		}
	}
	if(n>1LL)
		ret *= 2;
	return ret;
}
```



### <u>nCr</u>

```
ll NcR(int n, int r)
{
    ll p = 1, k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            ll m = __gcd(p, k);
            p /= m;
            k /= m;

            n--;
            r--;
        }

    }

    else
        p = 1;

    return p;
}
```

#### <u>nCr mod P</u>

```
const ll P = 998244353;
const ll N = 300003;
ll F[N];
ll power(ll a, ll n)//a^n
{
    ll ret = 1;
    while(n)
	{
        if(n&1)
			ret = (ret * a) % P;
        n /= 2;
        a = (a * a) % P;
    }
    return ret;
}
ll modInverse(ll n)
{
	return power(n, P - 2LL);
}
ll nCr(ll n, ll r)
{
	if(n < r) return 0;
	return (F[n] *  modInverse(F[r]) % P *  modInverse(F[n-r]) % P) % P; 
}
void solve()
{
	F[0] = F[1] = 1;
	for(ll i = 2; i<N; i++)
		F[i] = (F[i-1] * i) % P;
		
	ll q;
	cin>>q;
	ll n, r;
	while(q--)
	{
		cin>>n>>r;
		cout<<nCr(n, r)<<nl;
	}
}
```



#### <u>Phi</u>

```
int phi(int n)
{
	int ans = n;
	for(int p = 2; p*p<=n;p++)
	{
		// Check p is a prime factor of n. 
		if(n % p == 0)
		{
			while(n % p == 0)
				n /= p; //divide all the factors of p
			ans -= ans/p;
		}
	}
	/*
	There can be only one prime 
	greater than sqrt(n) that divides n
	*/
	if(n > 1)
		ans -= ans/n;
	return ans;
}
```

#### <u>Euler Totient Precompute</u>

```
#define mx 100005
int phi[mx];
void euler_totient()
{
	for(int i=0; i<mx; i++) phi[i]=i;
	
	for(int i=2; i<mx; i++)
	{
		if(phi[i]==i)
		{
			for(int j=i; j<mx; j+=i)
				phi[j]-=(phi[j]/i);
		}
	}
}
```

#### <u>Divisors</u>

```
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
```

```

// function to print the divisors 
void printDivisors(int n) 
{ 
	// Vector to store half of the divisors 
	vector<int> v; 
	for (int i=1; i<=sqrt(n); i++) 
	{ 
		if (n%i==0) 
		{ 
			if (n/i == i) // check if divisors are equal 
				printf("%d ", i); 
			else
			{ 
				printf("%d ", i); 

				// push the second divisor in the vector 
				v.push_back(n/i); 
			} 
		} 
	} 

	// The vector will be printed in reverse 
	for (int i=v.size()-1; i>=0; i--) 
		printf("%d ", v[i]); 
} 
```



#### <u>Prime Factorization</u>

```
map<int, int> primeFact(int n)
{
	map<int, int> mp;
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
			mp[i] = cnt;	
		}
	}
	if(n>1)	
		mp[n] = 1;
	return mp;
}
```

#### <u>Binary Exponentiation</u>

```
ll power(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)// IF ODD
			res *= a, n--;
		else
			n /= 2, a *= a;
	}
	return res;
}
```



```
ll power(ll a, ll n, ll p)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)// IF ODD
			res = (res*a) % p, n--; 
		else
			n /= 2, a =(a*a) % p;
	}
	return res;
}
```

#### <u>Graph Algorithm</u>

```
const int N = 100000;
vector<int> adj[N];
vector<bool> vis(N);

void dfs(int v)
{
	vis[v] = true;
	for(int i = 0; i<adj[v].size(); i++)
	{
		int child = adj[v][i];
		if(!vis[child])
			dfs(child);
	}
}
int main()
{
	int node,edge;
	scanf("%d%d",&node,&edge);
//    adj.assign(n,vector<int>());
//    vis.assign(n,false);
	for(int i = 0; i<edge; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
    return 0;
}
```

#### <u>BFS</u>

```
const int N = 100000;
vector<int> adj[N];
vector<bool> vis(N);
using namespace std;
void bfs(int n)
{
	queue <int> q;
	vis[n] = true;
	q.push(n);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for(int u : adj[v])
		{
			if(!vis[u])
				vis[u] = true, q.push(u);
		}
	}
}
```

#### <u>Subtree Calculation</u>

```
const int N = 2e5+5;
vector<int> adj[N];
vector<bool> vis(N);
int subtsize[N];
int dfs(int n, int d)
{
	vis[n] = true;
	int cnt = 1;
	for(int u : adj[n])
	{
		if(!vis[u])
		{
			int c =	dfs(u, d+1);
			cnt += c;
		}
	}
	return subtsize[n] = cnt;
}
int main()
{
	int n, k;
	scanf("%d",&n);
	for(int i = 0; i<n-1; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,1);
	for(int i = 1; i<=n; i++)
		printf("%d ",subtsize[i]);
	printf("\n");
    return 0;
}
```

#### <u>String Algorithm</u>

##### <u>KMP</u>

```
const int N = 1e6 + 2;
int lps[N]; //longest prefix suffix 
char s[N],p[N];
void kmpPreprocess(char *s)
{
	int len = strlen(s);
	lps[0] = 0;
	for(int i = 1, j = 0; i<len;)
	{
		if(s[i] != s[j])
		{
			if(j != 0)
				j = lps[j-1];
			else
				lps[i] = 0, i++;
		}
		else
			lps[i] = j+1, j++,i++;
	}
}
int kmp(char *text, char *pattern)
{
	kmpPreprocess(pattern);
	int j = 0,cnt = 0;
	int ps =  strlen(pattern);
	int sz = strlen(text);
	for(int i = 0; i<sz;)
	{	
		if(text[i] == pattern[j]) i++,j++;
		else
		{
			if(j != 0) j = lps[j-1];	
			else i++;		
		}
		if(j==ps)
			cnt++;
	}
	return cnt;
}
```

#### <u>Z Algorithm</u>

```
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
	string text = "pealmazumderpealpeal";
	string pattern = "peal";
	string combine = pattern + "@" + text;
	vector<int> v = zFunction(combine);
	for(int i = 0; i<sz(v); i++)
		cout<<v[i]<<" ";
    return 0;
}
```

```
	Fast multiplication and Division by 2
n = n<<1; //Multiply n with 2(Left Shift)
n = n>>1; //Divide n by 2(Right Shift)
	Swapping of 2 number using XOR
A ^=B; B^=A; A^=B ; // A quick way to swap a and b
	Avoiding use of strlen()
for(i=0;s[i];i++){….}//Loop breaks when the character array ends
	Calculating the number of digits directly
Number of digits in n = floor(log10(n)+1);
	Efficient way to know if a number is a power of 2
Bool isPowerOfTwo(int x)
Return x&&(!x&(x-1));
	Name of arguments in macros 
Use # sign to get exact name of an argument passed to a macro
#define what_is(x) cerr<<#x<<”is”<<x<<endl;
Int a_variable = 376;
What_is(a_variable);//Print “a_variable is 376”
What_is(a_variable * 2 +1);//Print”a_variable*2+1 is 753”
	Sort&for each loop
Vector <int> v={3,1,2,1,8}
Sort(begin(v),end(v),[](int a, int b){return a>b;});
For(auto I : v) cout<<I<<” ”;//Output –8 3 2 1 1
	Stop when both Integers are zero(0)
Int a,b;
While(scanf(“%d%d”,&a,&b),(a||b))
	Printf(“%d\n”,a+b);
	EOF input
Int a,b;
//scanf returns the number of items read
While(scanf(“%d%d”,&a,&b)==2)
//or I can check for EOF i.e
//while (scanf(“%d%d”,&a,&b)!=EOF)
Printf(“%d\n”,a+b);
	Taking blank lines only between test cases
int a,b,c=1;
while(scanf(“%d%d”,&a,&b)!=EOF){
    if(c>1)
	printf(“\n”);
    printf(“Case %d: %d\n”,c++,a+b);
	1<<j means 2j //left shifting  
•	Left shifting an integer ‘x’ with an integer ‘y’ (x<<y) is equivalent to multiplying x with 2^y
•	Right shifting an integer ‘x’ with an integer ‘y’ (x<<y) is equivalent to dividing x with 2^y

Identity Elements:
	X + 0 = X	X- 0 = X
	X * 1 = X	X/1 = X
	X XOR 0 = X
XOR
A ^ A = 0; 0 ^ A = A;

```

