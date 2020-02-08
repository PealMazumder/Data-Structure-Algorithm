#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int arr[]={4,5,67,2,1,78,8};
    for(int i=1;i<=7;i++)
    {
        for(int j=0;j<7;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int i=0;i<7;i++)
    cout<<arr[i]<<endl;
    return 0;
}
