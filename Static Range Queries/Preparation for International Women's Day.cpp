#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int n, k, ans = 0; cin >> n >> k;
    vector<int> frq(k);

    for (int i = 0, x; i < n && cin >> x; i++)
    {
        x %= k;
        if (frq[(k - x) % k])
            ans += 2, frq[(k - x) % k]--;
        else
            frq[x]++;
    }

    cout << ans;
}