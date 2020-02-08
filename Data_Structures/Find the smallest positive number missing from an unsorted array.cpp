#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i = 0; i<n; i++)
        cin>>arr[i];

    unordered_map<int, int> ump;
    for(int i = 0; i<n; i++)
    {
        if(arr[i]>0)
            ump[arr[i]]++;
    }

    int value = 1;

    while(true)
    {
        if(ump.find(value)==ump.end())
        {
            cout<<"Smallest positive missing number is : "<< value << endl;
            break;
        }
        value++;
    }

    return 0;
}
