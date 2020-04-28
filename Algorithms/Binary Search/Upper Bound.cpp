#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &ar, int target){
  int left = 0, right = ar.size() - 1,idx = -1;
  while(left <= right)
  {
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    
    if(ar[mid] == target)
    {
    	idx = mid;
    	left = mid + 1;
	}
    else if(ar[mid] < target) 
		left = mid + 1;
    else
		right = mid - 1;
		
  }
  if(idx < 0) return left;
  return idx+1;
}
int main()
{
	int n;
	cin>>n;
	vector<int> ar(n);
	for(int i = 0; i<n; i++)
		cin>>ar[i];
	int target;
	cin>>target;
	cout<<"Upper bound of "<<target<<" is "<<binarySearch(ar,target)<<"\n";
    return 0;
}
