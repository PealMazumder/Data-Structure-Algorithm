### **<u>What is Dynamic Programming?</u>**

Dynamic Programming (DP) is an algorithmic technique for solving an optimization problem by breaking it down into simpler subproblems and utilizing the fact that the optimal solution to the overall problem depends upon the optimal solution to its subproblems.

##### **Characteristics of Dynamic Programming**

1. Overlapping Subproblems
2. Optimal Substructure Property

##### Overlapping Subproblems:

Subproblems are smaller versions of the original problem. Any problem has overlapping sub-problems if finding its solution involves solving the same subproblem multiple times

##### Optimal Substructure Property:

Any problem has optimal substructure property if its overall optimal solution can be constructed from the optimal solutions of its subproblems. 

##### Dynamic Programming Methods

1. Top-down with Memorization
2. Bottom-up with Tabulation

##### Top-down with Memorization:

In this approach, we try to solve the bigger problem by recursively finding the solution to smaller sub-problems. Whenever we solve a sub-problem, we cache its result so that we don’t end up solving it repeatedly if it’s called multiple times. Instead, we can just return the saved result. This technique of storing the results of already solved subproblems is called Memorization.

##### Bottom-up with Tabulation:

Tabulation is the opposite of the top-down approach and avoids recursion. In this approach, we solve the problem “bottom-up” (i.e. by solving all the related sub-problems first). This is typically done by filling up an n-dimensional table. Based on the results in the table, the solution to the top/original problem is then computed.

##### Where can we use it?

1. Counting problems
2. Maximization/Minimization problems

##### Defining a DP Problem:

1. State
2. Return Values
3. Base Case
4. Transitions
5. Memorization

##### Problem-01:

###### Given a 2xN Grid, how many ways we can cover the whole grid with tiles 2x1 and 2x2? Rotation allowed/Rotation not allowed. Print answer modulo 1000000007.

```c++
#define	mod	1000000007
ll dp[2005];
ll totalNumberOfWay(ll pos)
{
	if(pos == 1) return 1;
	if(pos == 2) return 2;// when rotation allowed, it returns 3;
	if(dp[pos] != -1) return dp[pos];
	
	return dp[pos] = (totalNumberOfWay(pos-1) % mod + totalNumberOfWay(pos-2) % mod) % mod;
}
void solve()
{
	ll n;
	cin>>n;
	memset(dp, -1, sizeof(dp));
	ll ans = totalNumberOfWay(n);
	cout<<ans<<nl;
}
```

##### Problem- 01.01:

###### You are given a 3xN grid. Given 3x1 and 3x2 tiles, what is the recurrence for f(n), Rotation allowed.

###### ====> f(N-1) + f(N-2) + 3f(N-3)

##### Problem-02:

###### Given an array with N integers, find a subsequence of this array to maximize the sum of the subsequence.

###### Condition: Can't take 2 consecutive numbers

```c++
ll dp[100005];
ll maximumSubsequenceSum(vector<int> &ar, int n, int pos)
{    
	if(pos >= n) return 0;
	if(dp[pos] != -1) return dp[pos];
	

	int a, b;
	a = maximumSubsequenceSum(ar, n, pos+1);//not taking current value
	b = maximumSubsequenceSum(ar, n, pos+2) + ar[pos];//taking current value
	
	return dp[pos] = max(a, b);

}
void solve()
{
	int n;
	cin>>n;
	memset(dp, -1, sizeof(dp));
	vector<int> ar(n);
	

	for(int i = 0; i<n; i++)
		cin>>ar[i];
		
	ll ans = maximumSubsequenceSum(ar, n, 0);
	cout<<ans<<nl;

}
```

##### Problem-02.01:

###### Given an array with N(<1000) integers. Find subsequence (Ab1, Ab2,.....) of this array to maximize the following expression:

​	1*Ab1 + 2*Ab2 + 3Ab3 + 4Ab4+.........

```c++
ll dp[1005][1005];
ll maximumSubsequenceSum(vector<int> &ar, int n, int pos, int pos2)
{    
	if(pos >= n) return 0;
	if(dp[pos][pos2] != -1) return dp[pos][pos2];
	

	int a, b;
	a = maximumSubsequenceSum(ar, n, pos+1, pos2);//not taking current value
	b = maximumSubsequenceSum(ar, n, pos+1, pos2+1) + pos2 * ar[pos];//taking current value
	
	return dp[pos][pos2] = max(a, b);

}
void solve()
{
	int n;
	cin>>n;
	memset(dp, -1, sizeof(dp));
	vector<int> ar(n);
	

	for(int i = 0; i<n; i++)
		cin>>ar[i];
		
	ll ans = maximumSubsequenceSum(ar, n, 0, 1);
	cout<<ans<<nl;

}
```

##### Problem-02.02:

###### Given an array with N(<100000) integers. Find a subsequence(Ab1, Ab2,....) of this array to maximize the following expression:

###### 	Ab1 - Ab2 + Ab3 - Ab4 + Ab5 -.......

```c++
ll dp[1005][2];
ll maximumSubsequenceSum(vector<int> &ar, int n, int pos, int type)
{    
	if(pos >= n) return 0;
	if(dp[pos][type] != -1) return dp[pos][type];
	

    int a, b;
    a = maximumSubsequenceSum(ar, n, pos+1, type);//not taking current value
    if(type == 1)
        b = maximumSubsequenceSum(ar, n, pos+1, type^1) + ar[pos];//taking current value
    else
        b = maximumSubsequenceSum(ar, n, pos+1, type^1) - ar[pos];//taking current value

    return dp[pos][type] = max(a, b);

}
void solve()
{
	int n;
	cin>>n;
	memset(dp, -1, sizeof(dp));
	vector<int> ar(n);
	

	for(int i = 0; i<n; i++)
		cin>>ar[i];
		
	ll ans = maximumSubsequenceSum(ar, n, 0, 1);
	
	cout<<ans<<nl;
}
```

##### Problem-02.02.01:

###### Given an array with N(<100000) integers. Find a subsequence(Ab1, Ab2,....) of this array to maximize the following expression: Ab1 - Ab2 + Ab3 - Ab4 + Ab5 -.....

###### Can't take consecutive numbers.

```c++
ll dp[1005][2];
ll maximumSubsequenceSum(vector<int> &ar, int n, int pos, int type)
{    
	if(pos >= n) return 0;
	if(dp[pos][type] != -1) return dp[pos][type];
	

	int a, b;
	a = maximumSubsequenceSum(ar, n, pos+1, type);//not taking current value
	if(type == 1)
		b = maximumSubsequenceSum(ar, n, pos+2, type^1) + ar[pos];//taking current value
	else
		b = maximumSubsequenceSum(ar, n, pos+2, type^1) - ar[pos];//taking current value
	
	return dp[pos][type] = max(a, b);

}
void solve()
{
	int n;
	cin>>n;
	memset(dp, -1, sizeof(dp));
	vector<int> ar(n);
	

	for(int i = 0; i<n; i++)
		cin>>ar[i];
		
	ll ans = maximumSubsequenceSum(ar, n, 0, 1);
	cout<<ans<<nl;

}
```

##### Problem- 03.01:

###### You are given N tasks. Each task has a starting time, finishing time and a profit. You can do any number of non-overlapping tasks and get the profit associated with them. Your goal is to maximize total profit.

```c++
ll dp[10004];
vector<int> st;
ll maximizeTotalProfit(vector<pair<int, pair<int, int> > > ar, int pos)
{
	if(pos >= sz(ar)) return 0;
	if(dp[pos] != -1) return dp[pos];
	
	int a, b;
	a = maximizeTotalProfit(ar, pos+1);
	auto upr = upper_bound(st.begin(), st.end(), ar[pos].second.first);
	b = maximizeTotalProfit(ar, upr- st.begin())+ar[pos].second.second;
	return dp[pos] = max(a, b);
}
void solve()
{
	int n, s, ft, p;
	cin>>n;
	vector<pair<int, pair<int, int> > > ar;
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i<n; i++)
	{
		cin>>s>>ft>>p;
		st.pb(s);
		ar.push_back({st[i], {ft, p}});
	}
	
	sort(st.begin(), st.end());
	sort(ar.begin(), ar.end());
	
	ll ans = maximizeTotalProfit(ar, 0);
	cout<<ans<<nl;
}
```

```
Input:
6
0 6 60
1 4 30
3 5 10
5 7 30
5 9 50
7 8 10

Output:
80
```



#### Resources:

https://www.youtube.com/watch?v=cbgdSX2pXcQ

https://www.educative.io/courses/grokking-dynamic-programming-patterns-for-coding-interviews/m2G1pAq0OO0