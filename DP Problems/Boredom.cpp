#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e5 + 1;
long long dp[N], frq[N];
long long solve(int mn, int mx)
{
    if(mn > mx) return 0;

    if(~dp[mn]) return dp[mn];

    return dp[mn] = max(mn * frq[mn] + solve(mn + 2, mx), solve(mn + 1, mx));
}
int main()
{
    FastIO;
    int n, mn = 1e5 + 1, mx = 0;
    cin >> n;

    for (int i = 0, x; i < n; i++)
    {
        cin >> x, frq[x]++;
        mx = max(mx, x), mn = min(mn, x);
    }
    memset(dp, -1, sizeof dp);

    cout << solve(mn, mx);
}