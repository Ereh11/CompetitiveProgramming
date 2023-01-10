#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
bool Can(ll val, ll k, vector<ll>& v)
{
    ll ans = val + v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] * 100LL > ans * k) return false;
        ans += v[i];
    }

    return true;
}
int main()
{
    FastIO;
    int t = 1;  cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        vector<ll> v(n);

        for (auto& it : v) cin >> it;
     
        ll l = 0, r = 1e12;
        while (l <= r)
        {
            ll mid = ((l + r) >> 1);
            if (Can(mid, k, v)) r = mid - 1;
            else l = mid + 1;
        }

        cout << l;
        cout << (t ? "\n" : "");
    }
}