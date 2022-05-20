ll Binay_Search(ll l, ll r, ll x)
{
    while(l <= r)
    {
        ll mid = (l + r)/2;
        if(ar[mid] == x) return mid;
        else if(ar[mid] < x) l = mid+1;
        else r = mid-1;
    }
    return -1;
}


ll Lower_Bound(ll l, ll r, ll x)
{
    while(l < r)
    {
        ll mid = (l + r)/2;
        if(ar[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

ll Upper_Bound(ll l, ll r, ll x)
{
    while(l < r)
    {
        ll mid = (l + r)/2;
        if(ar[mid] > x) r = mid;
        else l = mid + 1;
    }
    return l;
}

ll Upper_Bound(ll l, ll r, ll x)
{
    while(l < r)
	{
        ll mid = (l + r)/2;
        if(ar[mid] <= x) l = mid + 1;
        else r = mid;
    }
    return l;
}
