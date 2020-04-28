#include<bits/stdc++.h>
using namespace std;
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
int main()
{
	int n;
	cin>>n;
	vector<int> ar(n);
	for(int i = 0; i<n; i++)
		cin>>ar[i];
	int target;
	cin>>target;
	cout<<binarySearch(ar,target)<<"\n";
    return 0;
}
