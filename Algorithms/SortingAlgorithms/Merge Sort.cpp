#include<bits/stdc++.h>
using namespace std;
void mergeArr(int ar[], int st, int mid, int en)
{
    int n = en - st + 1;
    int temp[n];

    int i = st, j = mid + 1, k = 0;

    while(i <= mid && j <= en)
    {
        if(ar[i] <= ar[j])
            temp[k] = ar[i], k++, i++;
        else
            temp[k] = ar[j], k++, j++;
    }

    while(i <= mid)
        temp[k] = ar[i], k++, i++;

    while(j <= en)
        temp[k] = ar[j], k++, j++;

    for(i = st; i <= en; i++)
        ar[i] = temp[i - st];
}
void mergeSort(int ar[], int st, int en)
{
    if(st < en)
    {
        int mid = (st + en) / 2;
        mergeSort(ar, st, mid);
        mergeSort(ar, mid + 1, en);
        mergeArr(ar, st, mid, en);
    }
}
void solve()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i = 0; i<n; i++)
        cin>>ar[i];

    mergeSort(ar, 0, n-1);

    for(int i = 0; i<n; i++)
        cout<<ar[i]<<" ";
    cout<<"\n";
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(NULL);
//    int t;
//    cin>>t;
//    while(t--)
        solve();
    return 0;
}
