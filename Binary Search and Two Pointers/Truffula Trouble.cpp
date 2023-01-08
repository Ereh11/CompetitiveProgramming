#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

bool check(ll d, int k, vector<int> &v)
{ 
    int cnt = 0;

    for (int i = 0; i < v.size(); i++)
        if (d >= v[i])  cnt++, d--, i++;

    return cnt >= k;
}
int main()
{
    FastIO;
    int n, k;  cin >> n >> k;

    vector<int> v(n);
    for (auto& it : v) cin >> it;

    ll l = 1, r = 1e14, ans = -1;
    while (l <= r)
    {
        ll mid = ((l + r) >> 1);
        if (check(mid, k, v)) 
            ans = mid, r = mid - 1;
        else 
            l = mid + 1;
    }

    cout << ans;
}