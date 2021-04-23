#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
int casino = 0;
#define ULL unsigned long long
const int N = 2000006;
const int M = 44444;
const ULL hs = 3797;

ULL F[N], H[N];
char in[N];
int n;

ULL seg(int x, int y) { // hash value of the segment [x, y]
    return H[y] - F[y - x + 1] * H[x - 1];
}
void solve()
{
    F[0] = 1; for(int i = 1; i < N; i++) F[i] = F[i - 1] * hs; // keeping the powers pre-calculated
    scanf("%s", in + 1); // 1 indexing
    n = strlen(in + 1);

    H[0] = 0; for(int i = 1; i <= n; i++) H[i] = H[i - 1] * hs + in[i];

    // now there will be qr queries and we need to check if seg[x, y] == seg[l, r]
    int qr; scanf("%d", &qr) ;
    while(qr--) {
        int x, y, l, r;
        scanf("%d %d %d %d", &x, &y, &l, &r);
        if(seg(x, y) == seg(l, r)) puts("YES");
        else puts("NO");
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(NULL);
//    int t;
//    cin>>t;
//    while(t--)
        solve();
    return 0;
}
