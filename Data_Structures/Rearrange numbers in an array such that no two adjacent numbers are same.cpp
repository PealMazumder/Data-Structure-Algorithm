#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000;
void rearrangeArray(int arr[],int n)
{
	int count[MAX] ={0};
	
	for(int i = 0; i<n; i++)
		count[arr[i]]++;
	
	priority_queue< pair<int, int> > pq;
	
	for(int i =0; i<n; i++)
	{
		if(count[arr[i]])
		{
			pq.push(make_pair(count[arr[i]],arr[i]));
			count[arr[i]] = 0;
		}
	}
	
	vector< int > v;
	
	pair<int, int> prev{-1,-1};
	
	while(!pq.empty())
	{
		pair<int, int> k = pq.top();
		pq.pop();
		
		v.push_back(k.second);
		
		if(prev.first>0)
			pq.push(prev);
			
		(k.first)--;
		prev = k;
	}
	if(v.size()!=n)
	{
		cout<<"Not valid"<<endl;
	}
		
	else
	{
		for(int i =0;i<v.size();i++)
			cout<<v[i]<<" ";
		cout<<endl;
	}
}
int main()
{
   	int n;
   	cin>>n;
	int arr[n];
	for(int i =0;i<n;i++)
		cin>>arr[i];
	 
	rearrangeArray(arr,n);
	return 0;
}
