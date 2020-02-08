#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int arr[]={4,5,67,2,1,78,8};
    for(int i=0;i<7;i++)
    {
        for(int j=i+1;j<7;j++)
        {
            if(arr[i]>arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
    }
    for(int i=0;i<7;i++)
    cout<<arr[i]<<endl;
    return 0;
}
