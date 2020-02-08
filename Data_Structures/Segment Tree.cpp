/*
  Point Update, Range Sum Query
*/
#include<bits/stdc++.h>
#define ll 						long long
#define nl 						"\n"

using namespace std;

const int N = 1e5+7;
int input[N];
ll segTree[4*N]

// Merge Left and Right
ll combine(ll left, ll right)
{
	return left + right;
}

void buildTree(int pos, int st, int en)
{
	if(st == en)
	{
		segTree[pos] = input[st]; ///Initialize
		return;
	}
	
	int mid = (st+en)/2;
	buildTree(2*pos, st, mid);
	buildTree(2*pos+1, mid+1, en);
	segTree[pos] = combine(segTree[2*pos], segTree[2*pos + 1]);
	
}
void updateTree(int pos, int st, int en,int idx, int value)
{
	if(idx<st||idx>en) return;
	if(st == en)
	{
	    segtree[pos] = value;
	    return;
	}
	
	int mid = (st+en)/2;
	updateTree(2*pos, st, mid,idx,value);
	updateTree(2*pos+1, mid+1, en,idx,value);
	segTree[pos] = combine(segTree[2*pos], segTree[2*pos + 1]);

}
ll query(int pos, int st, int en, int qst, int qen)
{
	if(qst<=st && en<=qen)
		return segTree[pos];		
	if(qen<st||qst>en) 
		return 0; //Proper Null Value
	
	int mid = (st + en)/2;
	return combine(query(2*pos, st, mid, qst, qen),query(2*pos+1, mid+1, en, qst, qen));
	
}
int main()
{
   
	return 0;
}

